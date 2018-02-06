#pragma once
#include "rpcNode.h"
#include "rpcLinkedList.h"

class rpcElement: rpcNode, rpcLinkedList
{
public:
	rpcElement();
	~rpcElement();
};

