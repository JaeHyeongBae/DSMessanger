#ifndef _SORTEDLISTDS_H
#define _SORTEDLISTDS_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "SortedListDS.h"

#define MAXSIZE 5

/**
*	array based simple unsorted list.
*/
template <class T>
public ref class SortedListDS
{
public:
	/**
	*	default constructor.
	*/
	SortedListDS()
	{
		m_Length = 0;
		ResetList();
	}

	/**
	*	destructor.
	*/
	~SortedListDS() {}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty()
	{
		m_Length = 0;
	}

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength()
	{
		return m_Length;
	}

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull()
	{
		if (m_Length > MAXSIZE - 1)
			return true;
		else
			return false;
	}

	/**
	*	@brief	primary key를 기준으로 정렬이 되도록 알맞은 자리에 항목을 추가한다.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(T^ inData)
	{
		if (!IsFull())	//꽉 차지 않았으면 항목을 추가한다.
		{
			if (m_Length == 0)	//Array에 아무 항목이 없으면 비교할 필요 없이 추가해준다.
			{
				m_Array[m_Length] = inData;
				m_Length++;
				return 1;	//항목을 추가했으므로 1을 리턴해준다.
			}
			else	//Array에 기존 항목이 존재할 때
			{
				for (int i = 0; i<m_Length; i++)
				{
					switch (m_Array[i].CompareByID(inData))	//Array에 존재하는 기존 항목의 ID와 사용자가 추가하고자 하는 신규 항목의 ID를 비교한다.
					{
					case LESS:	//기존의 항목이 더 작을때(신규 항목이 더 클때)
						if (i == m_Length - 1)	//Array의 마지막에 도달했는데도 신규 항목이 더 크면 가장 큰 값이므로 마지막에 추가해준다.
						{
							m_Array[m_Length] = inData;
							m_Length++;
							return 1;	//성공적으로 추가했으므로 1을 리턴하고 length를 1 늘려준다.
						}
						break;	//Array의 마지막이 아닌데도 기존의 항목이 더 작으면 Array의 다음 항목과 비교를 위해 switch문을 빠져나온다.
					case GREATER:	//기존의 항목이 더 클때(신규 항목이 더 작을때)
						for (int j = m_Length; j>i; j--)	//기존의 항목들을 1칸씩 뒤로 옮긴다.
						{
							m_Array[j] = m_Array[j - 1];
						}
						m_Array[i] = inData;	//신규 항목을 Array에 추가해준다.
						m_Length++;
						return 1;	//성공적으로 추가했으므로 1을 리턴하고 length를 1 늘려준다.
						break;
					case EQUAL:	//기존의 항목과 같을 때
						return -1;	//중복되는 값이므로 추가할 수 없다. -1을 리턴해준다.
						break;
					}
				}
			}
		}
		else	//꽉 찼으므로 추가할 수 없다.
			return 0;	//0을 리턴해준다.
	}

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList()
	{
		m_CurPointer = -1;
	}

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T^ data)
	{
		m_CurPointer++;	// list pointer 증가
		if (m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
			return -1;
		data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

		return m_CurPointer;
	}

	/**
	*	@brief	일부만 채워져있는 data에 알맞은 정보를 저장한다.
	*	@pre	data의 ID 변수는 채워져있어야 한다.
	*	@post	data 안의 멤버 변수가 모두 채워진다.
	*	@param	data : 일부만 채워져있는 T.
	*	@return	찾으면 1, 찾지 못하면 0을 리턴한다.
	*/
	int Get(T^ data)
	{
		for (int i = 0; i<m_Length; i++)
		{
			if (m_Array[i].GetId() == data.GetId())	//data와 'm_Array 중 하나의 항목'의 ID값이 같을 때
			{
				data = m_Array[i];
				return 1;	//data에 복사해준 뒤 1을 리턴한다.
			}
		}
		return 0;	//찾지 못하면 0을 리턴한다.
	}

	/**
	*	@brief	사용자가 지정한 T를 배열에서 삭제한다.
	*	@pre	data의 ID 변수는 채워져있어야 한다.
	*	@post	사용자가 입력한 항목은 삭제되고 length가 1줄어든다.
	*	@param	data : 일부만 채워져있는 T.
	*	@return 삭제에 성공했으면 1, 아니면 0을 리턴한다.
	*/
	int Delete(T^ data)
	{
		for (int i = 0; i<m_Length; i++)
		{
			if (m_Array[i].GetId() == data.GetId())	//data와 'm_Array 중 하나의 항목'의 ID값이 같을 때
			{
				for (int j = i; j<m_Length - 1; j++)
				{
					m_Array[j] = m_Array[j + 1];
				}
				m_Length--;	//지울 항목의 자리에 다음 항목을 복사하고 이것을 마지막 항목까지 반복한다. m_Length를 1 줄여준다.
				return 1;	//항목을 삭제하는데 성공했으므로 1을 리턴해준다.
			}
		}
		return 0;	//항목을 삭제하는데 실패했으므로 0을 리턴해준다.
	}

	/**
	*	@brief	사용자가 지정한 T에 해당하는 배열의 자리에 파라미터의 내용을 복사한다.
	*	@pre	data의 모든 변수가 채워져있어야 한다.
	*	@post	사용자가 지정한 항목이 data와 같아진다.
	*	@param	data : 모든 변수가 채워져있는 T.
	*	@return	성공적으로 수정했으면 1, 아니면 0을 리턴한다.
	*/
	int Replace(T^ data)
	{
		for (int i = 0; i<m_Length; i++)
		{
			if (m_Array[i].GetId() == data.GetId())	//data와 'List 중 하나의 항목'의 ID값이 같을 때
			{
				m_Array[i].SetRecord(data.GetId(), data.GetName(), data.GetBirthday(), data.GetGender(), data.GetPhoneNumber(), data.GetPassword(), data.GetProfileImage());	//data의 내용을 List의 항목에 복사한다.
				return 1;	//항목을 수정하는데 성공했으므로 1을 리턴해준다.
			}
		}
		return 0;	//항목을 수정하는데 실패했으므로 0을 리턴해준다.
	}

	/**
	*	@brief	일부만 채워져있는 data에 알맞은 정보를 저장한다. 대상을 찾을때 Binary Search를 이용한다.
	*	@pre	data의 ID 변수는 채워져있어야 한다.
	*	@post	data 안의 멤버 변수가 모두 채워진다.
	*	@param	data : 일부만 채워져있는 T.
	*	@return	찾으면 1, 찾지 못하면 0을 리턴한다.
	*/
	int GetByBinarySearch(T^ data)
	{
		int first = 0;
		int last = m_Length - 1;
		bool found = 0;
		while (first <= last && !found)	//first가 last보다 커지면 더이상 진행하지 않는다. found가 1이 되면 진행하지 않는다.
		{
			int mid = (first + last) / 2;	//mid는 first와 last의 평균값
			switch (data.CompareByID(m_Array[mid]))	//data와 m_Array[mid]의 ID값 비교
			{
			case LESS:
				last = mid - 1;
				break;	//data의 ID값이 더 작을때, last를 mid-1로 옮겨준다.
			case GREATER:
				first = mid + 1;
				break;	//data의 ID값이 더 클때, first를 mid+1로 옮겨준다.
			case EQUAL:
				data = m_Array[mid];
				found = 1;
				return 1;	//data와 m_Array[mid]의 ID값이 같으면 data에 객체를 복사해주고 1을 리턴한다. 반복문을 빠져나오기 위해 found=1을 해준다.
				break;
			}
		}
		return 0;	//찾지 못했으므로 0을 리턴해준다.
	}

private:
	T^ m_Array[MAXSIZE];  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

#endif	// _SORTEDLIST_H