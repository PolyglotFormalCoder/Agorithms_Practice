#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class InsertionSort
{
public:
    InsertionSort(std::vector<int> x):input(x){}
    void Sort()
    {
        //iterate n-1 times, index
        for (int index=0; index < input.size(); index++)
        {
            if(is_smaller(index))
            {
                // move it to front
                int temp = input[index];
                std::cout<<"temp: "<<temp<<std::endl; 
                input.erase(input.begin()+index);
                output_display();
                input.insert(input.begin(), temp);
            }
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
bool is_smaller(int index)
{
    bool result = false;
    if (input[index]<input[0])
    {
       result = true;     
    }
return result;
}

std::vector<int> input;
};

int main()
{
    std::vector<int> vec1 = {10,9,8,7,66,5};
    InsertionSort sort(vec1);
    sort.Sort();
    sort.output_display();
    return 0;
}