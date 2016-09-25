#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
 
using namespace std;
 
class GraphMatrix
{
    private:
        int n;
        int **adj;
        bool *visited;
 
        vector <string> label;
 
    public:
        GraphMatrix(const vector<string>&labels):
            n (labels.size()),
            label(labels)
        {
            visited = new bool [n];
            adj = new int* [n];
 
            for (int i = 0; i < n; i++)
            {
                adj[i] = new int [n];
 
                for(int j = 0; j < n; j++)
                {
                    adj[i][j] = 0;
                }
            }
        }
 
        bool add_edge(const string &origin, const string &destin)
        {
 
            vector<string>::iterator opos, dpos;
            opos = std::find(label.begin(), label.end(), origin);
            dpos = std::find(label.begin(), label.end(), destin);
 
 
            if (opos == label.end() || dpos == label.end()) return false;
 
            int x = opos-label.begin();
            int y = dpos-label.begin();
            adj[x][y] = 1;
            return true;
        }
            /*
 
            */
 
 
        void List()
        {
            cout << "\nMatrix Graph\n" << endl;
            cout << '\t';
            for(int i = 0; i < n; i++)
            {
                cout << label[i].c_str() << "  ";
            }
            cout << '\n';
            for(int i = 0; i < n; i++)
            {
                cout << label[i].c_str() << "\t";
 
                for(int j = 0; j < n; j++)
                {
                    cout << adj[i][j] << "  ";
                }
 
                cout<<endl;
            }
        }
};
 
 
int main()
{
    string  origin, destin;
    int nodes, max_edges;
 
    //char label[] =  {'A', 'B', 'C', 'D', 'E'};
    //label [ 0 ] = 'A';
 
    vector<string> label;
 
    cout << "How many points? ";
    cin >> nodes;
    std::cin.ignore(); //discard 1 character
    label.resize(nodes);
    cout << "Label the points: \n";
    for(int i = 0; i < nodes; i++ )
    {
        cout << "Enter label for point # " << i << " ";
        getline(cin ,label[i] );
    }  
 
 
    GraphMatrix graph(label);
 
    max_edges = nodes * (nodes - 1);
 
        for (int i = 0; i < max_edges; i++)
        {
            cout << "Define edges between two points (q q to exit): ";
 
            cin >> origin >> destin;
 
            if((origin == "q") && (destin == "q"))
            {
                break;
            }
 
            graph.add_edge(origin, destin);
        }
 
    graph.List();
 
    return 0;
}
