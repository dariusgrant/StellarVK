#pragma once
#include <map>
#include <any>
#include <typeindex>

namespace stellar {
	/// <summary>
	/// A map containing extensions for Vulkan object crreation 
	/// and querying. 
	/// </summary>
	class ExtensionMap {
	private:
		std::map<std::size_t, std::any> map;
		void* pStart = nullptr;
		void** pEnd = nullptr;

	public:
		/// <summary>
		/// Adds an extension to the map. The extension must be a
		/// valid extension for the associated Vulkan object per the
		/// specification.
		/// </summary>
		/// <typeparam name="Extension">The extension's type.</typeparam>
		/// <param name="extension_">The extension to add.</param>
		/// <returns>The extension map with the added extension.</returns>
		template <typename Extension>
		ExtensionMap& add( const Extension& extension_ ) {
			auto typeIndex = std::type_index( typeid(Extension) );
			auto hash = typeIndex.hash_code();
			map[hash] = extension_;
			Extension& obj = std::any_cast<Extension&>(map[hash]);

			if( pStart == nullptr ) {
				pStart = &obj;
			}
			else {
				*pEnd = &obj;
			}

			pEnd = const_cast<void**>(&obj.pNext);

			return *this;
		}

		/// <summary>
		/// Adds extensions to the map. The extensions must be a
		/// valid extension for the associated Vulkan object per the
		/// specification.
		/// </summary>
		/// <typeparam name="Extension">The first extension type.</typeparam>
		/// <typeparam name="...Extensions">The rest of the extensions' types.</typeparam>
		/// <param name="first_"> The first extension to add.</param>
		/// <param name="...rest_">The rest of the extensions to add, if applicable.</param>
		/// <returns>The extension map with the added extensions.</returns>
		template <typename Extension, typename... Extensions>
		ExtensionMap& add( const Extension& first_, const Extensions&... rest_ ) {
			add( first_ );
			add( rest_... );
			return *this;
		}

		/// <summary>
		/// Gets an extension from the extension map if it exists.
		/// </summary>
		/// <typeparam name="Extension">The type of extension to get.</typeparam>
		/// <returns>A pointer to the extension if it exists. Otherwise null pointer.</returns>
		template <typename Extension>
		const Extension* get() const {
			auto typeIndex = std::type_index( typeid(T) );
			const auto& res = find<T>();
			return res != map.end() ? std::any_cast<T*>(&res->second) : nullptr;
		}

		/// <summary>
		/// Gets the chain containing all the extensions. Necessary for
		/// passing into creation and query structures.
		/// </summary>
		/// <returns>A void pointer that links all the extensions.</returns>
		void* get_chain() const;


	private:
		/// <summary>
		/// Finds the extension based on its type.
		/// </summary>
		/// <typeparam name="Extension">The type of extension to find.</typeparam>
		/// <returns>An iterator at the extension if it exists. Otherwise, past-the-end iterator.</returns>
		template <class Extension>
		std::map<std::size_t, std::any>::iterator find() {
			return map.find( typeid(Extension).hash_code() );
		}
	};

}