//  blockchain demo
//
//  Created by Steven Bui on 5/1/19.
//  Copyright � 2019 Steven Bui. All rights reserved.
//
#pragma once
#include <cstdint>
#include <iostream>
#include <sstream>
#include <time.h>
#include "picosha2.h"
#include "jsoncpp/json/json.h"

using namespace std;

class Block {
public:

    Block(uint32_t index, const string &data);

    string getHash();
    void print();
    Json::Value getJson();
    string calculateHash(uint64_t nonce, string prevHash);

private:
    uint32_t m_index{ 0 };
    int64_t m_nonce{ -1 };
    string m_data;
    string m_hash;
    time_t m_time;
};