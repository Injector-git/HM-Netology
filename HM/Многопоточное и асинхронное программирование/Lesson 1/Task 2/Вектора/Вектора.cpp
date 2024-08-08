#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std::chrono_literals;

void static sum(std::vector<int>v1, std::vector<int>v2, int start, int end) {

        std::transform(v1.begin() + start, v1.begin() + end, v2.begin(), v1.begin(), std::plus<int>());

}

//class Threading {
//public:
//    Threading(int number) {
//        for (int i = 0; i < number; i++) {
//            v1.push_back(i); v2.push_back(i + 6);
//        }
//    }
//    std::vector<int> get_v1() {
//        return v1;
//    }
//    std::vector<int> get_v2() {
//        return v2;
//    }
//    int get_num() {
//        return number;
//    }
//private:
//    std::vector<int> v1;
//    std::vector<int> v2;
//    int number;
//};

int main()
{
    std::vector<int> v1;//1000
    std::vector<int> v2;//1000
    std::vector<int> v3;//10000
    std::vector<int> v4;//10000
    std::vector<int> v5;//100000
    std::vector<int> v6;//100000
    std::vector<int> v7;//1000000
    std::vector<int> v8;//1000000
    int thread_number{ 0 };
    const std::vector<int> vec_thread_number{ 0,1,2,4,8,16 };

    int thousand{ 1000 };
    for (int i = 0; i < thousand; i++) {
        v1.push_back(i); v2.push_back(i + 6);
    }

    int ten_thousand{ 10000 };
    for (int i = 0; i < ten_thousand; i++) {
        v3.push_back(i); v4.push_back(i + 6);
    }

    int one_hundred_thousand{ 100000 };
    for (int i = 0; i < one_hundred_thousand; i++) {
        v5.push_back(i); v6.push_back(i + 6);
    }

    int million{ 1000000 };
    for (int i = 0; i < million; i++) {
        v7.push_back(i); v8.push_back(i + 6);
    }
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " - concurrent threads are supported.\n\n";

    std::cout << "\t\t 1000 \t\t 10000 \t\t 100000 \t 1000000 \n";

    std::vector<std::thread> Threading(vec_thread_number.back());

    for (int i{ 0 }; i < vec_thread_number.size() - 1; i++)
    {
        {
            thread_number++;
            std::cout << vec_thread_number[thread_number] << " thread \t";

            //1000
            int shift = thousand / vec_thread_number[thread_number];//сдвиг
            int left_border{ 0 };//левая и правая границы
            int right_border{ shift };
            for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
                if (left_border == 0)
                    Threading[i] = (std::thread(sum, std::ref(v1), std::ref(v2), left_border, right_border));
                else
                    Threading[i] = (std::thread(sum, std::ref(v1), std::ref(v2), left_border + 1, right_border));

                left_border += shift;
                right_border += shift;
            }

            auto start = std::chrono::steady_clock::now();
            for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
                Threading[i].join();
            }
            auto end = std::chrono::steady_clock::now();

            std::chrono::duration<double> elapsed_seconds = end - start;
            std::cout << elapsed_seconds.count() << "s\t";


            //10000

            shift = ten_thousand / vec_thread_number[thread_number];//сдвиг
            left_border = 0;//левая и правая границы
            right_border = shift;
            for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
                if (left_border == 0)
                    Threading[i] = (std::thread(sum, std::ref(v3), std::ref(v4), left_border, right_border));
                else
                    Threading[i] = (std::thread(sum, std::ref(v3), std::ref(v4), left_border + 1, right_border));

                left_border += shift;
                right_border += shift;
            }

            start = std::chrono::steady_clock::now();
            for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
                Threading[i].join();
            }
            end = std::chrono::steady_clock::now();

            elapsed_seconds = end - start;
            std::cout << elapsed_seconds.count() << "s\t";

            //100000

            shift = one_hundred_thousand / vec_thread_number[thread_number];//сдвиг
            left_border = 0;//левая и правая границы
            right_border = shift;
            for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
                if (left_border == 0)
                    Threading[i] = (std::thread(sum, std::ref(v5), std::ref(v6), left_border, right_border));
                else
                    Threading[i] = (std::thread(sum, std::ref(v5), std::ref(v6), left_border + 1, right_border));

                left_border += shift;
                right_border += shift;
            }

            start = std::chrono::steady_clock::now();
            for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
                Threading[i].join();
            }
            end = std::chrono::steady_clock::now();

            elapsed_seconds = end - start;
            std::cout << elapsed_seconds.count() << "s\t";

            //1000000

            shift = million / vec_thread_number[thread_number];//сдвиг
            left_border = 0;//левая и правая границы
            right_border = shift;
            for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
                if (left_border == 0)
                    Threading[i] = (std::thread(sum, std::ref(v7), std::ref(v8), left_border, right_border));
                else
                    Threading[i] = (std::thread(sum, std::ref(v7), std::ref(v8), left_border + 1, right_border));

                left_border += shift;
                right_border += shift;
            }

            start = std::chrono::steady_clock::now();
            for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
                Threading[i].join();
            }
            end = std::chrono::steady_clock::now();

            elapsed_seconds = end - start;
            std::cout << elapsed_seconds.count() << "s\t";
            std::cout << std::endl;

        }
    }

    /*{
        thread_number++;//1
        std::cout << vec_thread_number[thread_number] <<" thread \t";

        //1000
        std::thread T1(sum, std::ref(v1), std::ref(v2), 0, thousand);

        auto start = std::chrono::steady_clock::now();
        T1.join();
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";

        //10000
        std::thread TT1(sum, std::ref(v3), std::ref(v4), 0, ten_thousand);

        start = std::chrono::steady_clock::now();
        TT1.join();
        end = std::chrono::steady_clock::now();

        elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";

        //100000
        std::thread OHT1(sum, std::ref(v5), std::ref(v6), 0, one_hundred_thousand);

        start = std::chrono::steady_clock::now();
        OHT1.join();
        end = std::chrono::steady_clock::now();

        elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";

        //1000000
        std::thread M1(sum, std::ref(v7), std::ref(v8), 0, million);

        start = std::chrono::steady_clock::now();
        M1.join();
        end = std::chrono::steady_clock::now();

        elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";
        std::cout << std::endl;
    }

    {
        thread_number++;//2
        std::cout << vec_thread_number[thread_number] << " thread \t";

        //1000
        std::thread T21(sum, std::ref(v1), std::ref(v2), 0, thousand / 2);
        std::thread T22(sum, std::ref(v1), std::ref(v2), (thousand / 2) + 1, thousand);

        auto start = std::chrono::steady_clock::now();
        T21.join();
        T22.join();
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";

        //10000
        std::thread TT21(sum, std::ref(v3), std::ref(v4), 0, ten_thousand/2);
        std::thread TT22(sum, std::ref(v3), std::ref(v4), (ten_thousand / 2) + 1, ten_thousand);

        start = std::chrono::steady_clock::now();
        TT21.join();
        TT22.join();
        end = std::chrono::steady_clock::now();

        elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";

        //100000
        std::thread OHT21(sum, std::ref(v5), std::ref(v6), 0, one_hundred_thousand/2);
        std::thread OHT22(sum, std::ref(v5), std::ref(v6), (one_hundred_thousand / 2)+1, one_hundred_thousand);

        start = std::chrono::steady_clock::now();
        OHT21.join();
        OHT22.join();
        end = std::chrono::steady_clock::now();

        elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";


        //1000000
        std::thread M21(sum, std::ref(v7), std::ref(v8), 0, million/2);
        std::thread M22(sum, std::ref(v7), std::ref(v8), (million / 2)+1, million);

        start = std::chrono::steady_clock::now();
        M21.join();
        M22.join();
        end = std::chrono::steady_clock::now();

        elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";
        std::cout << std::endl;
    }

    {
        thread_number++;//4
        std::cout << vec_thread_number[thread_number] << " thread \t";

        std::vector<std::thread> Threading(4);

        //1000
        int shift = thousand / vec_thread_number[thread_number];//сдвиг
        int left_border{ 0 };//левая и правая границы
        int right_border{ shift };
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            if(left_border==0)
            Threading[i] = (std::thread(sum, std::ref(v1), std::ref(v2), left_border, right_border));
            else
            Threading[i] = (std::thread(sum, std::ref(v1), std::ref(v2), left_border +1, right_border));

            left_border += shift;
            right_border += shift;
        }

        auto start = std::chrono::steady_clock::now();
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            Threading[i].join();
        }
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";


        //10000

        shift = ten_thousand / vec_thread_number[thread_number];//сдвиг
        left_border = 0;//левая и правая границы
        right_border = shift;
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            if (left_border == 0)
                Threading[i] = (std::thread(sum, std::ref(v3), std::ref(v4), left_border, right_border));
            else
                Threading[i] = (std::thread(sum, std::ref(v3), std::ref(v4), left_border + 1, right_border));

            left_border += shift;
            right_border += shift;
        }

        start = std::chrono::steady_clock::now();
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            Threading[i].join();
        }
        end = std::chrono::steady_clock::now();

        elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";

        //100000

        shift = one_hundred_thousand / vec_thread_number[thread_number];//сдвиг
        left_border = 0;//левая и правая границы
        right_border = shift;
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            if (left_border == 0)
                Threading[i] = (std::thread(sum, std::ref(v5), std::ref(v6), left_border, right_border));
            else
                Threading[i] = (std::thread(sum, std::ref(v5), std::ref(v6), left_border + 1, right_border));

            left_border += shift;
            right_border += shift;
        }

        start = std::chrono::steady_clock::now();
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            Threading[i].join();
        }
        end = std::chrono::steady_clock::now();

        elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";

        //1000000

        shift = million / vec_thread_number[thread_number];//сдвиг
        left_border = 0;//левая и правая границы
        right_border = shift;
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            if (left_border == 0)
                Threading[i] = (std::thread(sum, std::ref(v7), std::ref(v8), left_border, right_border));
            else
                Threading[i] = (std::thread(sum, std::ref(v7), std::ref(v8), left_border + 1, right_border));

            left_border += shift;
            right_border += shift;
        }

        start = std::chrono::steady_clock::now();
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            Threading[i].join();
        }
        end = std::chrono::steady_clock::now();

        elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";
        std::cout << std::endl;
    }

    {
        thread_number++;//8
        std::cout << vec_thread_number[thread_number] << " thread \t";

        std::vector<std::thread> Threading(8);

        //1000
        int shift = thousand / vec_thread_number[thread_number];//сдвиг
        int left_border{ 0 };//левая и правая границы
        int right_border{ shift };
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            if (left_border == 0)
                Threading[i] = (std::thread(sum, std::ref(v1), std::ref(v2), left_border, right_border));
            else
                Threading[i] = (std::thread(sum, std::ref(v1), std::ref(v2), left_border + 1, right_border));

            left_border += shift;
            right_border += shift;
        }

        auto start = std::chrono::steady_clock::now();
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            Threading[i].join();
        }
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";


        //10000

        shift = ten_thousand / vec_thread_number[thread_number];//сдвиг
        left_border = 0;//левая и правая границы
        right_border = shift;
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            if (left_border == 0)
                Threading[i] = (std::thread(sum, std::ref(v3), std::ref(v4), left_border, right_border));
            else
                Threading[i] = (std::thread(sum, std::ref(v3), std::ref(v4), left_border + 1, right_border));

            left_border += shift;
            right_border += shift;
        }

        start = std::chrono::steady_clock::now();
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            Threading[i].join();
        }
        end = std::chrono::steady_clock::now();

        elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";

        //100000

        shift = one_hundred_thousand / vec_thread_number[thread_number];//сдвиг
        left_border = 0;//левая и правая границы
        right_border = shift;
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            if (left_border == 0)
                Threading[i] = (std::thread(sum, std::ref(v5), std::ref(v6), left_border, right_border));
            else
                Threading[i] = (std::thread(sum, std::ref(v5), std::ref(v6), left_border + 1, right_border));

            left_border += shift;
            right_border += shift;
        }

        start = std::chrono::steady_clock::now();
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            Threading[i].join();
        }
        end = std::chrono::steady_clock::now();

        elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";

        //1000000

        shift = million / vec_thread_number[thread_number];//сдвиг
        left_border = 0;//левая и правая границы
        right_border = shift;
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            if (left_border == 0)
                Threading[i] = (std::thread(sum, std::ref(v7), std::ref(v8), left_border, right_border));
            else
                Threading[i] = (std::thread(sum, std::ref(v7), std::ref(v8), left_border + 1, right_border));

            left_border += shift;
            right_border += shift;
        }

        start = std::chrono::steady_clock::now();
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            Threading[i].join();
        }
        end = std::chrono::steady_clock::now();

        elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";
        std::cout << std::endl;

    }


    {
        thread_number++;//16
        std::cout << vec_thread_number[thread_number] << " thread \t";

        std::vector<std::thread> Threading(16);

        //1000
        int shift = thousand / vec_thread_number[thread_number];//сдвиг
        int left_border{ 0 };//левая и правая границы
        int right_border{ shift };
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            if (left_border == 0)
                Threading[i] = (std::thread(sum, std::ref(v1), std::ref(v2), left_border, right_border));
            else
                Threading[i] = (std::thread(sum, std::ref(v1), std::ref(v2), left_border + 1, right_border));

            left_border += shift;
            right_border += shift;
        }

        auto start = std::chrono::steady_clock::now();
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            Threading[i].join();
        }
        auto end = std::chrono::steady_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";


        //10000

        shift = ten_thousand / vec_thread_number[thread_number];//сдвиг
        left_border = 0;//левая и правая границы
        right_border = shift;
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            if (left_border == 0)
                Threading[i] = (std::thread(sum, std::ref(v3), std::ref(v4), left_border, right_border));
            else
                Threading[i] = (std::thread(sum, std::ref(v3), std::ref(v4), left_border + 1, right_border));

            left_border += shift;
            right_border += shift;
        }

        start = std::chrono::steady_clock::now();
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            Threading[i].join();
        }
        end = std::chrono::steady_clock::now();

        elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";

        //100000

        shift = one_hundred_thousand / vec_thread_number[thread_number];//сдвиг
        left_border = 0;//левая и правая границы
        right_border = shift;
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            if (left_border == 0)
                Threading[i] = (std::thread(sum, std::ref(v5), std::ref(v6), left_border, right_border));
            else
                Threading[i] = (std::thread(sum, std::ref(v5), std::ref(v6), left_border + 1, right_border));

            left_border += shift;
            right_border += shift;
        }

        start = std::chrono::steady_clock::now();
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            Threading[i].join();
        }
        end = std::chrono::steady_clock::now();

        elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";

        //1000000

        shift = million / vec_thread_number[thread_number];//сдвиг
        left_border = 0;//левая и правая границы
        right_border = shift;
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            if (left_border == 0)
                Threading[i] = (std::thread(sum, std::ref(v7), std::ref(v8), left_border, right_border));
            else
                Threading[i] = (std::thread(sum, std::ref(v7), std::ref(v8), left_border + 1, right_border));

            left_border += shift;
            right_border += shift;
        }

        start = std::chrono::steady_clock::now();
        for (int i{ 0 }; i < vec_thread_number[thread_number]; i++) {
            Threading[i].join();
        }
        end = std::chrono::steady_clock::now();

        elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << "s\t";
        std::cout << std::endl;
    }*/

    return 0;
}
