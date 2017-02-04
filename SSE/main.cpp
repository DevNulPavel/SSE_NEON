#include <emmintrin.h>
#include <math.h>
#include <chrono>
#include <iostream>

using namespace std;

// https://felix.abecassis.me/2011/09/cpp-getting-started-with-sse/



void normalSqrt(float* a, int N) {
    for (int i = 0; i < N; ++i)
        a[i] = sqrt(a[i]);
}

void sseSqrt(float* transformArray, int N) {
    // SSE позволяет упаковать в одно значение сразу четыре флоата
    // поэтому нужно в 4 раза меньше итераций
    int nb_iters = N / 4;
    __m128* arrayPointer = (__m128*)transformArray;


    for (int i = 0; i < nb_iters; ++i){
        // Вычисляем корень
        __m128 sqrtValue = _mm_sqrt_ps(*arrayPointer);

        // сохраняем
        _mm_store_ps(transformArray, sqrtValue);

        // смещаем указатель на исходные данные
        ++arrayPointer;

        // смещаем указатель на результирующие данные
        transformArray += 4;
    }
}

void normalSumArrays(const float* a, const float* b, int N, float* res){                                                                                                                                                                                                                
  for (int i = 0; i < N; ++i){
      res[i] = a[i] + b[i];
  }
}

void sseSumArrays(const float* a, const float* b, int N, float* res){
    // в четыре раза меньше итераций
    int nb_iters = N / 4;                                                                                                                                                                                         

    // указатели
    float* resPtr = res;
    __m128* aPtr = (__m128*)a;
    __m128* bPtr = (__m128*)b;    

    for (int i = 0; i < nb_iters; ++i){
        // сумма сразу 4х флоатов
        __m128 sumValue = _mm_add_ps(*aPtr, *bPtr);

        // сохраняем в резльтат
        _mm_store_ps(resPtr, sumValue);

        // смещение указателей на исходные и конечные данные
        ++aPtr;
        ++bPtr;

        // смещение результата на 4ре вычисленых значения
        resPtr += 4;
    }                                                                                                                                                                  
}

// void sse(char* a, const char* b, int N)                                                                                                                                                                          
// {                                                                                                                                                                                                                
//   int nb_iters = N / 16;                                                                                                                                                                                         
 
//   __m128i* l = (__m128i*)a;                                                                                                                                                                                      
//   __m128i* r = (__m128i*)b;                                                                                                                                                                                      
 
//   for (int i = 0; i < nb_iters; ++i, ++l, ++r)                                                                                                                                                                   
//     _mm_store_si128(l, _mm_add_epi8(*l, *r));                                                                                                                                                                    
// }

void fillArray(float* array, int N, float value){
    for (int i = 0; i < N; ++i){
        array[i] = value;
    }
}

int main(int argc, char** argv) {
    if (argc != 2)
        return 1;

    int N = atoi(argv[1]);

    // создаем выровненный буффер x=(float *)_mm_malloc(N*sizeof(float),16);
    // с размером кратным 128 битам (16 байтам) __m128
    float* a = 0;
    posix_memalign((void**)&a, 16,  N * sizeof(float));
    float* b = 0;
    posix_memalign((void**)&b, 16,  N * sizeof(float));
    float* result = 0;
    posix_memalign((void**)&result, 16,  N * sizeof(float));

    // fill
    fillArray(a, N, 123321.0f);
    fillArray(b, N, 4534.0f);
    fillArray(result, N, 0);

    // Нормальное вычисление
    {
        chrono::time_point<chrono::system_clock> start = std::chrono::system_clock::now();

        // normalSqrt(a, N);
        normalSumArrays(a, b, N, result);

        chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
        int elapsedMilisec = chrono::duration_cast<chrono::milliseconds>(end-start).count();
        cout << "Normal = " << elapsedMilisec << "msec" << endl;
    }

    // fill
    fillArray(a, N, 123321.0f);
    fillArray(b, N, 4534.0f);
    fillArray(result, N, 0);

    // SSE
    {
        chrono::time_point<chrono::system_clock> start = std::chrono::system_clock::now();

        // sseSqrt(a, N);
        sseSumArrays(a, b, N, result);

        chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
        int elapsedMilisec = chrono::duration_cast<chrono::milliseconds>(end-start).count();
        cout << "SSE = " << elapsedMilisec << "msec" << endl;
    }

    // _mm_free(x);
    free(a);
    free(b);
    free(result);
}