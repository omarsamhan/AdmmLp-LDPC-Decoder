#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

struct code_struct {
    int n; // Code length
    int k; // Code dimention
    int m; // # of rows in parity check matrix
    int d_c; // check degree (regular only)
    int d_v; // variable degree (regular only)
    vector<int> row_density;
    vector<int> col_density;
    vector< vector<int> > chk2var_conn;
    vector< vector<int> > var2chk_conn;
};


code_struct read_alist(string filename);
