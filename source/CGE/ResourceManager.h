#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <string>

namespace CGE
{
    /**************************
    *   Class for managing resources.
    *
    *   Keeps track of all loading/unloading of a specified
    *   resource, and ensures that that resource is not
    *   loaded more than once.
    **************************/
    template<typename T>
    class ResourceManager
    {
        public:
            ResourceManager();
            virtual ~ResourceManager();

            T* load(const char* inFile);
            void unload(const char* inFile);

            void unloadAll();

        protected:
            /// maps each resource to its filepath
            /// so we can use that to keep track of it
            std::map<std::string, T*> mResources;

        private:
    };

    template<typename T>
    ResourceManager<T>::ResourceManager()
    {
    }

    template<typename T>
    ResourceManager<T>::~ResourceManager()
    {
        unloadAll();
    }

    /**************************
    *   Loads the T form of a resource from the passed in file.
    *   Returns a pointer to the loaded resource.
    *
    *   If the resource has already been loaded, returns a pointer
    *   to the existing resource in memory (prevents loading it
    *   multiple times).
    *
    *   IMPORTANT: Do NOT call delete on the returned pointer.
    *   Instead, call ResourceManager::unload or ResourceManager
    *   will clean the resource pointed to for you when it is
    *   destroyed.
    **************************/
    template<typename T>
    T* ResourceManager<T>::load(const char* inFile)
    {
        typename std::map<std::string, T*>::iterator it =
            mResources.find(inFile);

        //we don't want to make the map search for the resource
        //twice
        T* resource = NULL;
        if (it == mResources.end())
        {
            resource = new T(inFile);
            mResources[inFile] = resource;
        }
        else
        {
            resource = it->second;
        }

        return resource;
    }

    /******************************
    *   Frees up the passed in resource from memory, if it
    *   has been loaded.
    *******************************/
    template<typename T>
    void ResourceManager<T>::unload(const char* inFile)
    {
        typename std::map<std::string, T*>::iterator it =
            mResources.find(inFile);

        if (it != mResources.end())
        {
            delete it->second;
            mResources.erase(it);
        }
    }

    /*****************************
    *   Frees up all resources loaded by this ResourceManager instance.
    ******************************/
    template<typename T>
    void ResourceManager<T>::unloadAll()
    {
        typename std::map<std::string, T*>::iterator it = mResources.begin();

        for (; it != mResources.end(); ++it)
        {
            delete it->second;
        }

        mResources.clear();
    }

}

#endif
