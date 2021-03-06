//  blockchain demo
//
//  Created by Steven Bui on 5/1/19.
//  Copyright � 2019 Steven Bui. All rights reserved.
//
#pragma once
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain {
public:
    Blockchain();
    Blockchain(Json::Value json);

    void createBlockchain(string json);
    void mineBlock(Block &block, string prevHash);
    void addBlock(string data);
    Block getBlock(int i) const;
    bool validateBlockchain();
    Json::Value getFullChain();
    bool resolveConflict(Blockchain &chain);
    vector<Block> getBlockchain();

private:
    const uint32_t m_difficulty{ 3 };
    vector<Block> m_chain;

    Block getLastBlock() const;
};