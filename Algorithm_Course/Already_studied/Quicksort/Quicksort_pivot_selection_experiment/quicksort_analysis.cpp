#include<iostream> 
#include<vector> 
#include<utility> // For std::swap 
#include<random> 
#include<algorithm> 
#include<chrono> 
#include<fstream> 
#include<iomanip> 



using namespace std; 

// Partition function: rearranges array around pivot 
int partitionLast(vector<int>& arr, int low, int high){
    int pivot = arr[high]; // Select last element as pivot 
    // Initialize Index: 'i' tracks the positon of the last element smaller than the pivot. 
    // Start at low - 1 because no elements have been processed yet. 
    int i = low - 1; // Index of smaller element. ? 

    // Iterate and Swap: Loop through the range [low, high-1]
    for(int j = low; j < high; ++j) {
        if(arr[j] <= pivot) {
            // If current element is smaller than or equal to pivot 
            i++; 
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[i+1], arr[high]); 
    return i  + 1; 
}


int partitionFirst(vector<int>& arr, int low, int high)
{
    int pivot = arr[low]; // Selecting first element as pivot 
    int i = high + 1; 

    for(int j = high; j> low; --j)
    {
        if(arr[j] >= pivot) {
            i--; 
            swap(arr[i], arr[j]); 
        }
    }

    swap(arr[i-1], arr[low]); 
    return i-1; 
}

int partitionMid(vector<int>& arr, int low, int high)
{
    int mid = low + (high - low) / 2;
    swap(arr[mid], arr[high]); 
    return  partitionLast(arr, low, high); 
}


int randomInt(int start, int end)
{
    static mt19937 generator(random_device{}()); 

    uniform_int_distribution<int> distribution(start, end); 

    return distribution(generator); 
}

int partitionRand(vector<int>& arr, int low, int high){
    int randomIndex = randomInt(low, high); 

    swap(arr[randomIndex], arr[high]); 

    return partitionLast(arr, low, high); 
}



// Quicksort function 
void quickSortFirst(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int pi = partitionFirst(arr, low, high); 
        quickSortFirst(arr, low, pi - 1); // Recursively sort left sub-array 
        quickSortFirst(arr, pi + 1, high); //Recursively sort right sub-array 

    }
}


// Quicksort function 
void quickSortLast(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int pi = partitionLast(arr, low, high); 
        quickSortLast(arr, low, pi - 1); // Recursively sort left sub-array 
        quickSortLast(arr, pi + 1, high); //Recursively sort right sub-array 

    }
}

// Quicksort function 
void quickSortMid(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int pi = partitionMid(arr, low, high); 
        quickSortMid(arr, low, pi - 1); // Recursively sort left sub-array 
        quickSortMid(arr, pi + 1, high); //Recursively sort right sub-array 

    }
}

// Quicksort function 
void quickSortRand(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int pi = partitionRand(arr, low, high); 
        quickSortRand(arr, low, pi - 1); // Recursively sort left sub-array 
        quickSortRand(arr, pi + 1, high); //Recursively sort right sub-array 

    }
}


void printArray(const vector<int>& arr)
{
    for(int value: arr)
        cout << value << " "; 

        cout << "\n"; 
}


// Input generators 
vector<int> generateRandomArray(int n)
{
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = randomInt(1, 100000);
    }

    return arr;
}

vector<int> generateDescendingArray(int n)
{
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i; 
    }
    return arr;
}


vector<int> generateAscendingArray(int n)
{
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = i+1; 
    }
    return arr;
}


// This function lets us measure any Quicksort functioni that has the same parameter structure 
using QuickSortFunction = void (*)(vector<int>&, int, int); 
//QuickSortFunction represents a pointer to a function that returns void and accepts vector<int>&, int, int

long long measureTime(vector<int>& arr, QuickSortFunction sortFunction)
{
    auto start = chrono::high_resolution_clock::now(); 

    sortFunction(arr, 0, static_cast<int>(arr.size()) - 1);  // Converts arr.size() from size_t to int before calculating the last index.

    auto stop = chrono::high_resolution_clock::now(); 

    return chrono::duration_cast<chrono::nanoseconds>(
        stop - start
    ).count(); 
}






int main()
{
    const int LIMIT = 5000;
    const int STEP = 10;
    const int REPETITIONS = 10;

    ofstream randomFile("random_results.csv");
    ofstream ascendingFile("ascending_results.csv");
    ofstream descendingFile("descending_results.csv");

    if (!randomFile || !ascendingFile || !descendingFile)
    {
        cout << "Could not create the result files.\n";
        return 1;
    }

    // Keep two digits after the decimal point in the CSV files.
    randomFile << fixed << setprecision(2);
    ascendingFile << fixed << setprecision(2);
    descendingFile << fixed << setprecision(2);

    // Column headings for all three tables.
    randomFile
        << "Array Size,First Pivot,Last Pivot,Middle Pivot,Random Pivot\n";

    ascendingFile
        << "Array Size,First Pivot,Last Pivot,Middle Pivot,Random Pivot\n";

    descendingFile
        << "Array Size,First Pivot,Last Pivot,Middle Pivot,Random Pivot\n";


    // ============================================================
    // Experiment 1: Random arrays
    // ============================================================

    cout << "Starting the random-array experiment...\n";

    for (int n = STEP; n <= LIMIT; n += STEP)
    {
        long long totalFirst = 0;
        long long totalLast = 0;
        long long totalMiddle = 0;
        long long totalRandom = 0;

        for (int run = 0; run < REPETITIONS; run++)
        {
            // A new random array is generated for every repetition.
            vector<int> original = generateRandomArray(n);

            // Each pivot strategy receives the same input.
            vector<int> firstArray = original;
            vector<int> lastArray = original;
            vector<int> middleArray = original;
            vector<int> randomArray = original;

            totalFirst += measureTime(firstArray, quickSortFirst);
            totalLast += measureTime(lastArray, quickSortLast);
            totalMiddle += measureTime(middleArray, quickSortMid);
            totalRandom += measureTime(randomArray, quickSortRand);

            // The correctness check is outside the timed section.
            if (!is_sorted(firstArray.begin(), firstArray.end()) ||
                !is_sorted(lastArray.begin(), lastArray.end()) ||
                !is_sorted(middleArray.begin(), middleArray.end()) ||
                !is_sorted(randomArray.begin(), randomArray.end()))
            {
                cout << "Sorting error in random array of size "
                     << n << '\n';

                return 1;
            }
        }

        double averageFirst =
            static_cast<double>(totalFirst) / REPETITIONS;

        double averageLast =
            static_cast<double>(totalLast) / REPETITIONS;

        double averageMiddle =
            static_cast<double>(totalMiddle) / REPETITIONS;

        double averageRandom =
            static_cast<double>(totalRandom) / REPETITIONS;

        randomFile
            << n << ","
            << averageFirst << ","
            << averageLast << ","
            << averageMiddle << ","
            << averageRandom << "\n";

        if (n % 500 == 0)
        {
            cout << "Random arrays completed up to size "
                 << n << '\n';
        }
    }


    // ============================================================
    // Experiment 2A: Ascending arrays
    // ============================================================

    cout << "\nStarting the ascending-array experiment...\n";

    for (int n = STEP; n <= LIMIT; n += STEP)
    {
        long long totalFirst = 0;
        long long totalLast = 0;
        long long totalMiddle = 0;
        long long totalRandom = 0;

        for (int run = 0; run < REPETITIONS; run++)
        {
            vector<int> original = generateAscendingArray(n);

            vector<int> firstArray = original;
            vector<int> lastArray = original;
            vector<int> middleArray = original;
            vector<int> randomArray = original;

            totalFirst += measureTime(firstArray, quickSortFirst);
            totalLast += measureTime(lastArray, quickSortLast);
            totalMiddle += measureTime(middleArray, quickSortMid);
            totalRandom += measureTime(randomArray, quickSortRand);

            if (!is_sorted(firstArray.begin(), firstArray.end()) ||
                !is_sorted(lastArray.begin(), lastArray.end()) ||
                !is_sorted(middleArray.begin(), middleArray.end()) ||
                !is_sorted(randomArray.begin(), randomArray.end()))
            {
                cout << "Sorting error in ascending array of size "
                     << n << '\n';

                return 1;
            }
        }

        double averageFirst =
            static_cast<double>(totalFirst) / REPETITIONS;

        double averageLast =
            static_cast<double>(totalLast) / REPETITIONS;

        double averageMiddle =
            static_cast<double>(totalMiddle) / REPETITIONS;

        double averageRandom =
            static_cast<double>(totalRandom) / REPETITIONS;

        ascendingFile
            << n << ","
            << averageFirst << ","
            << averageLast << ","
            << averageMiddle << ","
            << averageRandom << "\n";

        if (n % 500 == 0)
        {
            cout << "Ascending arrays completed up to size "
                 << n << '\n';
        }
    }


    // ============================================================
    // Experiment 2B: Descending arrays
    // ============================================================

    cout << "\nStarting the descending-array experiment...\n";

    for (int n = STEP; n <= LIMIT; n += STEP)
    {
        long long totalFirst = 0;
        long long totalLast = 0;
        long long totalMiddle = 0;
        long long totalRandom = 0;

        for (int run = 0; run < REPETITIONS; run++)
        {
            vector<int> original = generateDescendingArray(n);

            vector<int> firstArray = original;
            vector<int> lastArray = original;
            vector<int> middleArray = original;
            vector<int> randomArray = original;

            totalFirst += measureTime(firstArray, quickSortFirst);
            totalLast += measureTime(lastArray, quickSortLast);
            totalMiddle += measureTime(middleArray, quickSortMid);
            totalRandom += measureTime(randomArray, quickSortRand);

            if (!is_sorted(firstArray.begin(), firstArray.end()) ||
                !is_sorted(lastArray.begin(), lastArray.end()) ||
                !is_sorted(middleArray.begin(), middleArray.end()) ||
                !is_sorted(randomArray.begin(), randomArray.end()))
            {
                cout << "Sorting error in descending array of size "
                     << n << '\n';

                return 1;
            }
        }

        double averageFirst =
            static_cast<double>(totalFirst) / REPETITIONS;

        double averageLast =
            static_cast<double>(totalLast) / REPETITIONS;

        double averageMiddle =
            static_cast<double>(totalMiddle) / REPETITIONS;

        double averageRandom =
            static_cast<double>(totalRandom) / REPETITIONS;

        descendingFile
            << n << ","
            << averageFirst << ","
            << averageLast << ","
            << averageMiddle << ","
            << averageRandom << "\n";

        if (n % 500 == 0)
        {
            cout << "Descending arrays completed up to size "
                 << n << '\n';
        }
    }


    randomFile.close();
    ascendingFile.close();
    descendingFile.close();

    cout << "\nAll experiments completed successfully.\n";
    cout << "Created files:\n";
    cout << "1. random_results.csv\n";
    cout << "2. ascending_results.csv\n";
    cout << "3. descending_results.csv\n";
    cout << "\nAll execution times are recorded in nanoseconds.\n";

    return 0;
}