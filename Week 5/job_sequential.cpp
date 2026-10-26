#include <iostream>
using namespace std;

struct Job
{
    char id;
    int deadline;
    int profit;
};

void jobSequencing(Job job[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(job[i].profit < job[j].profit)
            {
                Job temp = job[i];
                job[i] = job[j];
                job[j] = temp;
            }
        }
    }

    int maxDeadline = 0;

    for(int i = 0; i < n; i++)
    {
        if(job[i].deadline > maxDeadline)
            maxDeadline = job[i].deadline;
    }

    char sequence[maxDeadline];
    bool slot[maxDeadline];

    for (int i = 0; i < maxDeadline; i++)
        slot[i] = false;

    int totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = job[i].deadline - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                sequence[j] = job[i].id;
                slot[j] = true;
                totalProfit += job[i].profit;
                break;
            }
        }
    }

    cout << "Job Sequence: ";

    for (int i = 0; i < maxDeadline; i++)
    {
        if (slot[i] == true)
            cout << sequence[i] << " ";
    }

    cout << "\nMaximum Profit = " << totalProfit << endl;
}

int main()
{
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    Job job[n];

    cout << "Enter Job ID, Deadline and Profit:\n";

    for (int i = 0; i < n; i++)
        cin >> job[i].id >> job[i].deadline >> job[i].profit;

    jobSequencing(job, n);

    return 0;
}
