#pragma once
#include <memory>
#include <vulkan/vulkan.hpp>
#include "ExtensionMap.hpp"

namespace stellar {
	/// <summary>
	/// The base for Vulkan objects that are created. This excludes
	/// objects that are retrieved from being enumerated.
	/// </summary>
	/// <typeparam name="VkUniqueObject">The unique Vulkan object (object wrapped in unique_ptr).</typeparam>
	/// <typeparam name="VkObject">The Vulkan object.</typeparam>
	/// <typeparam name="VkFlags">The flags associated with the object's creation.</typeparam>
	template<class VkUniqueObject, class VkObject, typename VkFlags>
	class UniqueObject {
	public:
		/// <summary>
		/// The builder associated with each UniqueObject to ensure the object
		/// is being built correctly.
		/// </summary>
		/// <typeparam name="DerivedUniqueObject">The object's type that's built by a derived class of UniqueObject.</typeparam>
		/// <typeparam name="DerivedBuilder">The builder's type derived from this class that's building the object.</typeparam>
		template <class DerivedBuilder, class DerivedUniqueObject>
		class Builder {
		public:
			std::unique_ptr<DerivedUniqueObject> derivedUniqueObject;

		public:
			/// <summary>
			/// Add flags for the creation of the object. The flags must be valid
			/// per the specification for the object.
			/// </summary>
			/// <param name="flags_">The flags to add.</param>
			/// <returns>The builder with the added flags.</returns>
			DerivedBuilder& add_flags( const VkFlags& flags_ ) {
				derivedUniqueObject->flags |= flags_;
				return dynamic_cast<DerivedBuilder&>(*this);
			}

			/// <summary>
			/// Add extension(s) to the object to be created with.
			/// </summary>
			/// <typeparam name="Extension">The type of the first extension.</typeparam>
			/// <typeparam name="...Extensions">The type of the rest of the extensions.</typeparam>
			/// <param name="first_">The first extension to add.</param>
			/// <param name="...rest_">The rest of the extensions to add, if applicable.</param>
			/// <returns>The builder with the added extension(s).</returns>
			template <typename Extension, typename... Extensions>
			DerivedBuilder& add_next_extension( const Extension& first_, const Extensions&... rest_ ) {
				derivedUniqueObject->extensionMap.add( first_, rest_... );
				return dynamic_cast<DerivedBuilder&>(*this);
			}

			/// <summary>
			/// Builds the objects by creating the underlying Vulkan object.
			/// </summary>
			/// <returns>The objected derived from UniqueObject.</returns>
			virtual DerivedUniqueObject&& build() = 0;
		};

	protected:
		VkUniqueObject uniqueObject;
		VkFlags flags;
		ExtensionMap extensionMap;

	public:
		/// <summary>
		/// Gets the unique Vulkan object.
		/// </summary>
		/// <returns>The unique Vulkan object.</returns>
		const VkUniqueObject& get_unique_object() const {
			return uniqueObject;
		}

		/// <summary>
		/// Gets the Vulkan object.
		/// </summary>
		/// <returns>The Vulkan object.</returns>
		const VkObject& get_object() const {
			return uniqueObject.get();
		}

		/// <summary>
		/// Gets the flags associated with the object's creation.
		/// </summary>
		/// <returns>The flags if any were set. Otherwise 0.</returns>
		const VkFlags& get_flags() const {
			return flags;
		}

		/// <summary>
		/// Gets the specified extension.
		/// </summary>
		/// <typeparam name="Extension">The type of extension.</typeparam>
		/// <returns>A pointer to the extension if it exists. Otherwise null pointer.</returns>
		template <typename Extension>
		const Extension* get_extension() const {
			return extensionMap.get<Extension>();
		}

		/// <summary>
		/// Destroys the object.
		/// </summary>
		void destroy() {
			uniqueObject.reset();
		}
	};
}