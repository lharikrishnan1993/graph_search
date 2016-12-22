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

std::vector <float*> getNeighbours(float* current_node)
{
    std::vector <float*> neighbours;
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if((*current_node + i - 1) != *current_node || (*(current_node+1) + j - 1) != *(current_node+1))
            {
                float temp[2] = {*current_node + i - 1, *(current_node+1) + j -1};
//                std::cout<<std::endl;
//                std::cout << temp[0] <<" "<< temp[1] << std::endl;
                neighbours.push_back(temp);
                std::cout << *current_node + i - 1 << " " << *(current_node+1) + j -1 << std::endl;
            }
        }
    }
    return neighbours;
}


std::vector <float*> astar(float *start, float *goal)
{
    priority_stack open_set;
    float initial_f_score = std::numeric_limits<float>::max();
    open_set.insert_node(start, initial_f_score);
    std::vector <float*> closed_set;
    float gCost = 0;

    while(*start != *goal && *(start+1) != *(goal+1))
    {

        float* current_node = open_set.pop();
        //std::vector <float*> neighbours = getNeighbours(current_node);

    }


    return closed_set;
}

int main(int argc, char* argv[])
{
    const int DIM = (argc-1)/2;
    float start[DIM];
    for (int i=1; i<DIM+1; i++) start[i-1] = (std::stof(argv[i]));

    float goal[DIM];
    for (int i=DIM+1; i<DIM+DIM+1; i++) goal[i-DIM-1] = (std::stof(argv[i]));

    //std::vector<float*> path = astar(start, goal);
    std::vector <float*> neighbours = getNeighbours(start);
    for (int i = 0; i < neighbours.size(); i++)
    {
        std::cout << *neighbours[i] << " " << *(neighbours[i] + 1) << std::endl;

    }
    return 0;
}
