//  blockchain demo
//
//  Created by Steven Bui on 5/1/19.
//  Copyright � 2019 Steven Bui. All rights reserved.
//
#include "Block.h"

Block::Block(uint32_t index, const string &data) : m_index(index), m_data(data), m_time(time(nullptr)) {
}

string Block::getHash() {
    return m_hash;
}

string Block::calculateHash(uint64_t nonce, string prevHash) {
    m_nonce = nonce;

    stringstream ss;
    ss << m_index << m_time << m_data << m_nonce << prevHash;

    std::vector<unsigned char> hash(picosha2::k_digest_size);
    picosha2::hash256(ss.str(), hash);

    string hex_str = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
    m_hash = hex_str;

    return hex_str;
}

// Returns a json object containing all the information inside the block
Json::Value Block::getJson() {
    Json::Value root;

    root["index"] = m_index;
    root["timestamp"] = m_time;
    root["data"] = m_data;
    root["proof"] = m_nonce;
    root["hash"] = m_hash;

    // TODO: remove debug output
    //cout << root << endl;

    return root;
}

// Prints all the information inside the block
void Block::print() {
    cout << "*** Block ***" << endl;
    cout << "Index: " << m_index << endl;
    cout << "Timestamp: " << m_time << endl;
    cout << "Data: " << m_data << endl;
    cout << "Nonce: " << m_nonce << endl;
    cout << "Hash: " << m_hash << endl;
}