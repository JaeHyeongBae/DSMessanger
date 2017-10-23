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
	*	@brief	primary key�� �������� ������ �ǵ��� �˸��� �ڸ��� �׸��� �߰��Ѵ�.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(T^ inData)
	{
		if (!IsFull())	//�� ���� �ʾ����� �׸��� �߰��Ѵ�.
		{
			if (m_Length == 0)	//Array�� �ƹ� �׸��� ������ ���� �ʿ� ���� �߰����ش�.
			{
				m_Array[m_Length] = inData;
				m_Length++;
				return 1;	//�׸��� �߰������Ƿ� 1�� �������ش�.
			}
			else	//Array�� ���� �׸��� ������ ��
			{
				for (int i = 0; i<m_Length; i++)
				{
					switch (m_Array[i].CompareByID(inData))	//Array�� �����ϴ� ���� �׸��� ID�� ����ڰ� �߰��ϰ��� �ϴ� �ű� �׸��� ID�� ���Ѵ�.
					{
					case LESS:	//������ �׸��� �� ������(�ű� �׸��� �� Ŭ��)
						if (i == m_Length - 1)	//Array�� �������� �����ߴµ��� �ű� �׸��� �� ũ�� ���� ū ���̹Ƿ� �������� �߰����ش�.
						{
							m_Array[m_Length] = inData;
							m_Length++;
							return 1;	//���������� �߰������Ƿ� 1�� �����ϰ� length�� 1 �÷��ش�.
						}
						break;	//Array�� �������� �ƴѵ��� ������ �׸��� �� ������ Array�� ���� �׸�� �񱳸� ���� switch���� �������´�.
					case GREATER:	//������ �׸��� �� Ŭ��(�ű� �׸��� �� ������)
						for (int j = m_Length; j>i; j--)	//������ �׸���� 1ĭ�� �ڷ� �ű��.
						{
							m_Array[j] = m_Array[j - 1];
						}
						m_Array[i] = inData;	//�ű� �׸��� Array�� �߰����ش�.
						m_Length++;
						return 1;	//���������� �߰������Ƿ� 1�� �����ϰ� length�� 1 �÷��ش�.
						break;
					case EQUAL:	//������ �׸�� ���� ��
						return -1;	//�ߺ��Ǵ� ���̹Ƿ� �߰��� �� ����. -1�� �������ش�.
						break;
					}
				}
			}
		}
		else	//�� á���Ƿ� �߰��� �� ����.
			return 0;	//0�� �������ش�.
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
		m_CurPointer++;	// list pointer ����
		if (m_CurPointer == MAXSIZE)	// end of list�̸� -1�� ����
			return -1;
		data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

		return m_CurPointer;
	}

	/**
	*	@brief	�Ϻθ� ä�����ִ� data�� �˸��� ������ �����Ѵ�.
	*	@pre	data�� ID ������ ä�����־�� �Ѵ�.
	*	@post	data ���� ��� ������ ��� ä������.
	*	@param	data : �Ϻθ� ä�����ִ� T.
	*	@return	ã���� 1, ã�� ���ϸ� 0�� �����Ѵ�.
	*/
	int Get(T^ data)
	{
		for (int i = 0; i<m_Length; i++)
		{
			if (m_Array[i].GetId() == data.GetId())	//data�� 'm_Array �� �ϳ��� �׸�'�� ID���� ���� ��
			{
				data = m_Array[i];
				return 1;	//data�� �������� �� 1�� �����Ѵ�.
			}
		}
		return 0;	//ã�� ���ϸ� 0�� �����Ѵ�.
	}

	/**
	*	@brief	����ڰ� ������ T�� �迭���� �����Ѵ�.
	*	@pre	data�� ID ������ ä�����־�� �Ѵ�.
	*	@post	����ڰ� �Է��� �׸��� �����ǰ� length�� 1�پ���.
	*	@param	data : �Ϻθ� ä�����ִ� T.
	*	@return ������ ���������� 1, �ƴϸ� 0�� �����Ѵ�.
	*/
	int Delete(T^ data)
	{
		for (int i = 0; i<m_Length; i++)
		{
			if (m_Array[i].GetId() == data.GetId())	//data�� 'm_Array �� �ϳ��� �׸�'�� ID���� ���� ��
			{
				for (int j = i; j<m_Length - 1; j++)
				{
					m_Array[j] = m_Array[j + 1];
				}
				m_Length--;	//���� �׸��� �ڸ��� ���� �׸��� �����ϰ� �̰��� ������ �׸���� �ݺ��Ѵ�. m_Length�� 1 �ٿ��ش�.
				return 1;	//�׸��� �����ϴµ� ���������Ƿ� 1�� �������ش�.
			}
		}
		return 0;	//�׸��� �����ϴµ� ���������Ƿ� 0�� �������ش�.
	}

	/**
	*	@brief	����ڰ� ������ T�� �ش��ϴ� �迭�� �ڸ��� �Ķ������ ������ �����Ѵ�.
	*	@pre	data�� ��� ������ ä�����־�� �Ѵ�.
	*	@post	����ڰ� ������ �׸��� data�� ��������.
	*	@param	data : ��� ������ ä�����ִ� T.
	*	@return	���������� ���������� 1, �ƴϸ� 0�� �����Ѵ�.
	*/
	int Replace(T^ data)
	{
		for (int i = 0; i<m_Length; i++)
		{
			if (m_Array[i].GetId() == data.GetId())	//data�� 'List �� �ϳ��� �׸�'�� ID���� ���� ��
			{
				m_Array[i].SetRecord(data.GetId(), data.GetName(), data.GetBirthday(), data.GetGender(), data.GetPhoneNumber(), data.GetPassword(), data.GetProfileImage());	//data�� ������ List�� �׸� �����Ѵ�.
				return 1;	//�׸��� �����ϴµ� ���������Ƿ� 1�� �������ش�.
			}
		}
		return 0;	//�׸��� �����ϴµ� ���������Ƿ� 0�� �������ش�.
	}

	/**
	*	@brief	�Ϻθ� ä�����ִ� data�� �˸��� ������ �����Ѵ�. ����� ã���� Binary Search�� �̿��Ѵ�.
	*	@pre	data�� ID ������ ä�����־�� �Ѵ�.
	*	@post	data ���� ��� ������ ��� ä������.
	*	@param	data : �Ϻθ� ä�����ִ� T.
	*	@return	ã���� 1, ã�� ���ϸ� 0�� �����Ѵ�.
	*/
	int GetByBinarySearch(T^ data)
	{
		int first = 0;
		int last = m_Length - 1;
		bool found = 0;
		while (first <= last && !found)	//first�� last���� Ŀ���� ���̻� �������� �ʴ´�. found�� 1�� �Ǹ� �������� �ʴ´�.
		{
			int mid = (first + last) / 2;	//mid�� first�� last�� ��հ�
			switch (data.CompareByID(m_Array[mid]))	//data�� m_Array[mid]�� ID�� ��
			{
			case LESS:
				last = mid - 1;
				break;	//data�� ID���� �� ������, last�� mid-1�� �Ű��ش�.
			case GREATER:
				first = mid + 1;
				break;	//data�� ID���� �� Ŭ��, first�� mid+1�� �Ű��ش�.
			case EQUAL:
				data = m_Array[mid];
				found = 1;
				return 1;	//data�� m_Array[mid]�� ID���� ������ data�� ��ü�� �������ְ� 1�� �����Ѵ�. �ݺ����� ���������� ���� found=1�� ���ش�.
				break;
			}
		}
		return 0;	//ã�� �������Ƿ� 0�� �������ش�.
	}

private:
	T^ m_Array[MAXSIZE];  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

#endif	// _SORTEDLIST_H