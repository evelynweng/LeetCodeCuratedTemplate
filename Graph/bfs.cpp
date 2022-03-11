#include<iostream>
#include<vector>
#include"treenode.h"
using namespace std;
/* 
Usage example:
(1) find shortest path, from upper_left (0,0) to bottom_right (size -1, size -1); 
(1.1) 0: can go, 1: cannot go
0 0 1 1 0 0
0 0 0 0 1 0
0 0 1 0 0 0

(2) return tree node by level
.......1...... <--- root
...2......3....
.4...5..6...7..
return: [[1], [2, 3], [4,5,6,7]]
*/
int Matrix_BFS(vector<vector<int>> &matrix){
    if(matrix[0][0] == 1) return -1; 
    const vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}}; // for four direction
    int m = matrix.size();
    int n = matrix[0].size();

    queue<int> node; // we don't want to push "pair", because it's slow
    node.push(0);  // push start point: question normally grant at least one point;
    int path = -1; // first point count as zero path
    
    while (!node.empty())
    {
        int size  = node.size();
        
        path += 1;

        while(size -- > 0){ // ** good tip: traverse by level, so no extra add for path **
            int cur  = node.front();
            node.pop();

            int row = cur / n;
            int col = cur % n;
            if(matrix[row][col] == 1) continue; // ***may add multiple times, don't walk again
            if(row == m - 1 && col == n - 1) return path; // ***return result if reach the target

            matrix[row][col] = 1; // mark as walked;
            
            for(auto dir: dirs){
                int newr = row + dir[0];
                int newc = col + dir[1];
                if(newr < 0 || newc < 0 || newr == m || newc == n || matrix[newr][newc] == 1)
                    continue; // elimated illeagle node        
                node.push(newr*n + newc);
            }
        }
    }
    return -1; // never get to the end;
}

vector<vector<int>> TreeLevel_BFS(TreeNode *root){
    if(!root) return {};
    vector<vector<int>> ret; // return array

    queue<TreeNode*> nodes;
    nodes.push(root);

    while(!nodes.empty()){

        int size = nodes.size();
        vector<int> subret; // for current level subarray

        while(size-- > 0){
            TreeNode *cur = nodes.front();
            nodes.pop();

            subret.push_back(cur->val);

            if(cur->left) nodes.push(cur->left);
            if(cur->right) nodes.push(cur->right);
        }
        ret.push_back(subret);
    }
    return ret;
}


int main(){
    vector<vector<int>> matrix = {
        {0,0,1,1,0,0},
        {0,0,0,0,1,0},
        {0,0,1,0,0,0}
    }

    TreeGenerator tree = TreeGenerator(8);
    TreeNode *root = tree.getRoot();

    int minPath = Matrix_BFS(matrix);
    cout<<"Matrix BFS minPath: "<< minPath<<endl;
    vector<vector<int>> treelevels = TreeLevel_BFS(root);
    for(auto treelevel: treelevels){
        cout<<"["
        for(auto val: treelevel){
            cout<<val<<",";
        }
        cout<<"],";
    }
    cout<<endl;

}