#pragma once

namespace YAFramework
{
	template <typename T>
	class ItemType
	{
	public:
		ItemType();
		ItemType(T item);
		~ItemType();
		ItemType(const ItemType& other);
		void SetItem(T item);
		T GetItem();
	private:
		T item;
	};

	template<typename T>
	ItemType<T>::ItemType()
	{
	}

	template<typename T>
	ItemType<T>::ItemType(T item)
	{
		this->item = item;
	}

	template<typename T>
	ItemType<T>::~ItemType()
	{
	}

	template<typename T>
	ItemType<T>::ItemType(const ItemType & other)
	{
		this->item = other.item;
	}

	template<typename T>
	void ItemType<T>::SetItem(T item)
	{
		this->item = item;
	}

	template<typename T>
	T ItemType<T>::GetItem()
	{
		return this->item;
	}
}

