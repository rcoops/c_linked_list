#pragma once
#include <string>
# include <sstream>

class rpcNode
{
public:
	rpcNode();
	rpcNode(int iData);

	int compareTo(rpcNode *pNode);

	std::string toString();

	~rpcNode();

protected:
	rpcNode *m_pNext;
	rpcNode *m_pLast;
	int m_iData;
	friend class rpcLinkedList;

};

