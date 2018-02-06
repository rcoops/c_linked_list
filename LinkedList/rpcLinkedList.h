#pragma once
#include "rpcNode.h"

class rpcLinkedList
{

public:
	enum sortOrder { ASC, DESC };
	rpcLinkedList();
	rpcLinkedList(int data);
	~rpcLinkedList();

	int getAt(int iIndex);

	void prepend(int iData);
	void append(int iData);
	void insertAt(int iIndex, int iData);

	int removeTail();
	int removeHead();
	int removeFrom(int iIndex);

	bool isEmpty();
	void sort(sortOrder order);
	int size();

	void printList();

protected:
	int m_iSize;
	rpcNode *m_pHead, *m_pTail;

	void add(int iData, rpcNode *pEndNode, rpcNode **pEndNodeConnector);

	void init(rpcNode *pNode);
	rpcNode* getNodeAt(int iIndex);
	void swap(rpcNode *pFirstNode, rpcNode *pSecondNode);
	bool shouldSwap(rpcNode *pFirstNode, rpcNode *pSecondNode, sortOrder order);

};

