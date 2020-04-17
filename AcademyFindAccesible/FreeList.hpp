#pragma once

#include <vector>
#include <cstdint>

namespace YAFramework
{
	template <typename T>
	struct FreeListNode
	{
		T data;
		std::int32_t next;
	};

	constexpr std::int32_t INVALID_INDEX{ -1 };

	template <typename T>
	class FreeList
	{
	public:
		void MakeEmpty(std::uint32_t size);
		void InsertToEnd(T data);
		void InsertAfter(std::uint32_t position, T val);
		void DeleteAfter(std::uint32_t position);
		FreeListNode<T> Get(std::int32_t position);
		std::int32_t GetHeadList();
	private:
		std::vector<FreeListNode<T>> arr;
		std::int32_t headList = 0;
		std::int32_t headFree = 0;
		std::int32_t lastPositionInserted = 0;
	};

	template<typename T>
	void FreeList<T>::MakeEmpty(std::uint32_t size)
	{
		this->headFree = 0;
		this->headList = INVALID_INDEX;
		this->lastPositionInserted = this->headFree;

		arr.resize(size);

		for (std::uint32_t i = 0; i < size; i++)
		{
			if (i == size-1)
			{
				arr[i].next = INVALID_INDEX;
				continue;
			}
			arr[i].next = i + 1;
		}
	}

	template<typename T>
	void FreeList<T>::InsertToEnd(T data)
	{
		if (this->headList == INVALID_INDEX)
		{
			this->InsertAfter(this->headFree, data);
		}
		else
		{
			this->InsertAfter(this->lastPositionInserted, data);
		}
	}

	template<typename T>
	void FreeList<T>::InsertAfter(std::uint32_t position, T data)
	{
		std::int32_t locNew = headFree;
		headFree = arr[headFree].next;

		if (headFree == INVALID_INDEX)
		{
			// Error - No More Free Space
			// Throw std::exception (not sure if i can use it)
			return;
		}

		arr[locNew].data = data;
		arr[locNew].next = arr[position].next;
		arr[position].next = locNew;

		if (headList == INVALID_INDEX)
		{
			headList = locNew;
		}

		this->lastPositionInserted = locNew;
	}

	template<typename T>
	void FreeList<T>::DeleteAfter(std::uint32_t position)
	{
		std::int32_t locFree = arr[position].next;

		if (locFree == this->lastPositionInserted)
		{
			this->lastPositionInserted = position;
		}

		arr[position].next = arr[locFree].next;
		// arr[locFree].data = nothing - we don't have default value because it is a template
		arr[locFree].next = headFree;
		headFree = locFree;
	}

	template<typename T>
	FreeListNode<T> FreeList<T>::Get(std::int32_t position)
	{
		return this->arr[position];
	}
	
	template<typename T>
	std::int32_t FreeList<T>::GetHeadList()
	{
		return this->headList;
	}
}