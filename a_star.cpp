#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

bool comp(const std::pair<float*, float> &a, const std::pair<float*, float> &b)
    {
        return a.second < b.second;
    }

struct priority_stack
{
    std::vector <std::pair< float*, float> > values;

    void insert_node(float* node, float f_score)
    {
        values.push_back(std::make_pair(node, f_score));
        std::sort(values.begin(), values.end(), comp);
    }

    float* pop()
    {
        float *temp = values[0].first;
        values.erase(values.begin(), values.begin()+1);
        return temp;
    }

    void print()
    {
        for (int i=0; i < values.size(); i++)
        {
            std::cout << values[i].first[0]<< " "<< values[i].first[1] << std::endl;
        }
    }
};

std::vector <float*> astar(float *start, float *goal)
{
    priority_stack open_set;
    float initial_f_score = std::numeric_limits<float>::max();
    open_set.insert_node(start, initial_f_score);
    open_set.insert_node(goal, 20.5);
    open_set.print();
    float* five = open_set.pop();
    std::cout << *five <<" " <<*(five + 1)<< std::endl;
    open_set.print();
    std::vector <float*> closed_set;


    return closed_set;
}

int main(int argc, char* argv[])
{
    const int DIM = (argc-1)/2;

    float start[DIM];
    for (int i=1; i<DIM+1; i++) start[i-1] = (std::stof(argv[i]));

    float goal[DIM];
    for (int i=DIM+1; i<DIM+DIM+1; i++) goal[i-DIM-1] = (std::stof(argv[i]));

    std::vector<float*> path = astar(start, goal);
    //for (int i=0; i<DIM; i++) std::cout<< *(path[1]+i) << std::endl;

    return 0;
}
