#include "stdafx.h"
#include "rpcLinkedList.h"
#include <iostream>

/* CONSTRUCTORS / DESTRUCTOR */

/**
 * Empty list
 */
rpcLinkedList::rpcLinkedList()
{
	init(nullptr);
}

/**
 * One element list
 */
rpcLinkedList::rpcLinkedList(int iData)
{
	init(new rpcNode(iData));
}

rpcLinkedList::~rpcLinkedList()
{
	rpcNode *pNode = m_pHead;
	while (pNode)
	{
		rpcNode *pNext = pNode->m_pNext;
		delete pNode;
		pNode = pNext;
	}
}

/* GET */

int rpcLinkedList::getAt(int iIndex)
{
	rpcNode *pNode = getNodeAt(iIndex);

	if (pNode) return pNode->m_iData;

	std::cout << "returning INT_MIN" << std::endl;
	return INT_MIN;
}

/* ADD */

void rpcLinkedList::prepend(int iData)
{
	if (m_pHead)
	{
		m_pHead->m_pLast = new rpcNode(iData);
		m_pHead->m_pLast->m_pNext = m_pHead;
		m_pHead = m_pHead->m_pLast;
		m_iSize++;
	}
	else init(new rpcNode(iData));
}

void rpcLinkedList::append(int iData)
{
	if (m_pTail)
	{
		m_pTail->m_pNext = new rpcNode(iData);
		m_pTail->m_pNext->m_pLast = m_pTail;
		m_pTail = m_pTail->m_pNext;
		m_iSize++;
	}
	else init(new rpcNode(iData));
}

void rpcLinkedList::insertAt(int iIndex, int iData)
{
	rpcNode *pNodeAtIndex = getNodeAt(iIndex);

	if (pNodeAtIndex == m_pHead || iIndex < 0) prepend(iData); // works for empty list (null node)
	else if (pNodeAtIndex == m_pTail || iIndex >= m_iSize) append(iData);
	else
	{
		rpcNode *pNewNode = new rpcNode(iData);
		pNewNode->m_pLast = pNodeAtIndex->m_pLast;
		pNewNode->m_pNext = pNodeAtIndex;
		if (pNewNode->m_pLast) pNewNode->m_pLast->m_pNext = pNewNode;
		if (pNewNode->m_pNext) pNewNode->m_pNext->m_pLast = pNewNode;

		m_iSize++;
	}
}

/* REMOVE */

/**
 * returns INT_MIN from empty list
 */
int rpcLinkedList::removeHead()
{
	int data = INT_MIN;
	rpcNode *pNodeToRemove = m_pHead;

	if (pNodeToRemove)
	{
		data = pNodeToRemove->m_iData;
		if (m_pTail == m_pHead) init(nullptr);
		else
		{
			m_pHead = pNodeToRemove->m_pNext;
			if (m_pHead) m_pHead->m_pLast = nullptr;
			pNodeToRemove->m_pNext = nullptr;
			m_iSize--;
		}
		
	}

	return data;
}

/**
* returns INT_MAX from empty list
*/
int rpcLinkedList::removeTail()
{
	int iData = INT_MAX;
	rpcNode *pNodeToRemove = m_pTail;

	if (pNodeToRemove)
	{
		iData = pNodeToRemove->m_iData;
		if (m_pTail == m_pHead) init(nullptr);
		else
		{
			m_pTail = pNodeToRemove->m_pLast;
			if (m_pTail) m_pTail->m_pNext = nullptr;
			pNodeToRemove->m_pLast = nullptr;
			m_iSize--;
		}

	}

	return iData;
}

/**
* returns INT_MAX if index out of bounds
*/
int rpcLinkedList::removeFrom(int iIndex)
{
	int iData = INT_MAX;
	rpcNode *pNodeToRemove = getNodeAt(iIndex);
	if (pNodeToRemove)
	{
		iData = pNodeToRemove->m_iData;
		if (pNodeToRemove == m_pTail) m_pTail = pNodeToRemove->m_pLast;
		else pNodeToRemove->m_pNext->m_pLast = pNodeToRemove->m_pLast;

		if (pNodeToRemove == m_pHead) m_pHead = pNodeToRemove->m_pNext;
		else pNodeToRemove->m_pLast->m_pNext = pNodeToRemove->m_pNext;
		pNodeToRemove->m_pNext = pNodeToRemove->m_pLast = nullptr;
		m_iSize--;
	}
	return iData;
}

/* MISC */

bool rpcLinkedList::isEmpty()
{
	return m_pHead == nullptr;
}

void rpcLinkedList::sort(sortOrder order)
{
	// selection sort
	if (isEmpty() || m_iSize == 1) return;
	for (rpcNode *pFirstLoopNode = m_pHead; pFirstLoopNode->m_pNext; pFirstLoopNode = pFirstLoopNode->m_pNext)
		for (rpcNode *pSecondLoopNode = pFirstLoopNode->m_pNext; pSecondLoopNode; pSecondLoopNode = pSecondLoopNode->m_pNext)
			if (shouldSwap(pFirstLoopNode, pSecondLoopNode, order)) swap(pFirstLoopNode, pSecondLoopNode);
}

void rpcLinkedList::printList()
{
	std::cout << "-------------------------" << std::endl;
	if (isEmpty()) std::cout << "Empty List" << std::endl;
	rpcNode *pCurrent = m_pHead;
	int i = 0;
	while (pCurrent)
	{
		std::cout << "Node: " << i << " - " << pCurrent->toString() << "" << std::endl;
		pCurrent = pCurrent->m_pNext;
		i++;
	}
	std::cout << "-------------------------" << std::endl;
}

int rpcLinkedList::size()
{
	return m_iSize;
}

// protected

void rpcLinkedList::init(rpcNode* pNode)
{
	m_pHead = m_pTail = pNode;
	m_iSize = pNode ? 1 : 0;
}

rpcNode* rpcLinkedList::getNodeAt(int iIndex)
{
	if (isEmpty() || iIndex < 0 || iIndex >= m_iSize)
	{
		std::cout << "index " << iIndex << " out of bounds" << std::endl;
		return nullptr;
	}

	rpcNode *pCurrent = m_pHead;
	for (int i = 0; i < iIndex; i++) pCurrent = pCurrent->m_pNext;
	return pCurrent;
}

void rpcLinkedList::swap(rpcNode *pFirstNode, rpcNode *pSecondNode)
{
	int iTemp = pFirstNode->m_iData;
	pFirstNode->m_iData = pSecondNode->m_iData;
	pSecondNode->m_iData = iTemp;
}

bool rpcLinkedList::shouldSwap(rpcNode *pFirstNode, rpcNode *pSecondNode, sortOrder order)
{
	return pFirstNode->compareTo(pSecondNode) == (order == DESC ? -1 : 1);
}
