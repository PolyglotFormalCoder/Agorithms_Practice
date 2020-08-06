#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class SelectionSort
{
public:
    SelectionSort(std::vector<int> x):input(x){}
    void Sort()
    {
        //iterate n-1 times, index
        for (int index=0; index < input.size()-1; index++)
        {
            //find min from index to n
            int location = find_min(index);
            std::cout<<"min: "<<index<<std::endl;
            // move it to front
            int temp = input[location];
            std::cout<<"temp: "<<temp<<std::endl; 
            input.erase(input.begin()+location);
            output_display();
            input.insert(input.begin()+index, temp);
            output_display();
        }
    }
    void output_display()
    {
        for (int index=0; index < input.size(); index++)
        {
            std::cout<<input[index]<<"  ";
        }
        std::cout<<std::endl;

    }

private:
int find_min(int index)
{
int min = input[index];
int location = index;
for (int i =index; i < input.size();i++)
{
    if (input[i]<min)
    {
        min = input[i];
        location = i;
    }
}
return location;
}

std::vector<int> input;
};

int main()
{
    std::vector<int> vec1 = {0,0,0,0,0,0,0,0,-1};
    SelectionSort sort(vec1);
    sort.Sort();
    sort.output_display();
    return 0;
}