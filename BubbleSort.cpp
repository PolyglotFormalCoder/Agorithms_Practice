#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class BubbleSort
{
public:
    BubbleSort(std::vector<int> x):input(x){}
    void Sort()
    {
        //number of passes
        for (int pass=0; pass < input.size()-1; pass++ )
        {
            //iterate n-1 times, index
            for (int index=0; index < input.size()-1; index++)
            {
                if(is_smaller(index))
                {
                    // swap neighbors
                    int temp = input[index];
                    input[index] = input[index+1];
                    input[index+1]= temp; 
                    output_display();                
                }                
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
    if (input[index+1]<input[index])
    {
       result = true;     
    }
return result;
}

std::vector<int> input;
};

int main()
{
    std::vector<int> vec1 = {10,9,8,7,5};
    BubbleSort sort(vec1);
    sort.Sort();
    std::cout<<"final output: "<<std::endl;
    sort.output_display();
    return 0;
}