//
// Created by nicholas on 2018/12/7.
//

#ifndef ALGORITHMTOYS_MAZE_H
#define ALGORITHMTOYS_MAZE_H

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cerrno>

using namespace std;

vector<vector<int> > readInput(string path) {

    char filepath[path.length()+1];
    filepath[path.length()] = '\0';
    path.copy(filepath, sizeof(filepath), 0);
    cout << filepath << endl;
    FILE* f;
    f = fopen(filepath, "r+");
    if (f == NULL) {
        cout << "fail to open the input file" << endl;
        strerror(errno);
        exit(EXIT_FAILURE);
    }

    int row, col;
    fscanf(f, "%d %d", &row, &col);

    vector<vector<int> > input;
    for (int k = 0; k < row; ++k) {
        vector<int> temp;
        for (int l = 0; l < col; ++l) {
            temp.push_back(0);
        }
        input.push_back(temp);
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            fscanf(f, "%d", &input[i][j]);
        }
    }

    fclose(f);

    return input;
}

//int maze(string in) {
//    //首先读入输入文件中的迷宫二维数组
//}



#endif //ALGORITHMTOYS_MAZE_H
