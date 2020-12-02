// lr10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
namespace fs = std::filesystem;

void demo_status(const fs::path& p, fs::file_status s) { 
    cout << p;
    if (fs::is_directory(s)) cout << " is a directory\n";
}

 
int main()

{
    fs:: path cur_path, new_path;
    string  command;
    cout << " to see the current path, press 1 \n";
    cout << " to see the directory's content , press 2 \n";
    cout << " if you want to create a new directory, press 3 \n";
    cout << " to see size of the directory, press 4\n";
    cout << " if you want to copy a file, press 5 \n";
    cout << " if you want to delete file, press 6 \n";
    cout << " if you want to delete all, press 7 \n";
    cout << " if you want to move up and down, press 8\n";
    cout << " if you want to rename your directory, press 9\n";
    cout << " if you want to move your file, press 10\n";


    int key;
    cout << " enter your key:" << endl;
    cin >> key;
    while (key != -1) {
        switch (key) {

        case 1:
            cout << "Current path is " << fs::current_path() << '\n';
            break;
        }

        switch (key) {
        case 2:
            fs::create_directories("sandbox/a/b");
            ofstream("sandbox/file1.txt");
            ofstream("sandbox/file2.txt");
            for (auto& p : fs::directory_iterator("sandbox"))
            {
                cout << p.path() << '\n';
            }
            fs::remove_all("sandbox");
            break;
        }


        switch (key) {
        case 3:
            fs::create_directory("sand");
            ofstream("sand/file");
            for (auto it = fs::directory_iterator("sand"); it != fs::directory_iterator(); ++it) {
                demo_status("sand", fs::status("sand"));     // не понял, какая должа быть проверка, написал такую, но в ней не уверен...
            }
            fs::remove_all("sand");
            break;
        }

        switch (key) {
        case 4:
            fs::path p = fs::current_path() / "example.bin";
            ofstream(p).put('d');
            cout << "File size = " << fs::file_size(p) << '\n';
            fs::remove(p);
            break;
        }
        switch (key) {
        case 5:
            fs::create_directory("sandbox");
            ofstream("sandbox/file1.txt").put('f');

            fs::copy_file("sandbox/file1.txt", "sandbox/file2.txt");
            cout << "file1.txt holds : "
                << ifstream("sandbox/file1.txt").rdbuf() << '\n';
            cout << "file2.txt holds : "
                << ifstream("sandbox/file2.txt").rdbuf() << '\n';
            fs::remove_all("sandbox");
            break;
        }

        switch (key) {
        case 6:
            ofstream("file1.txt").put('a');
            int d = fs::remove("file1.txt");
            cout << "was deleted: " << d << " element" << '\n';
            break;
        }
        switch (key)
        {
        case 7:
            fs::create_directories("sand");
            fs::create_directories("sandbox");
            ofstream("sandbox/file3.txt");
            ofstream("sandbox/file4.txt");
            ofstream("sand/file1.txt");
            ofstream("sand/file2.txt");
            int k = fs::remove_all("sand");
            cout << "were deleted: " << k << " elements" << '\n';
            break;

        }
        switch (key)
        {
        case 8:


            cout << "enter the command" << endl;
            cin >> command;
            if (command == "up")
            {
                cur_path = fs::current_path() / "sand";
                fs::create_directory("sand");
                fs::current_path(cur_path);
                cout << fs::current_path() << '\n';
            }
            if (command == "down")
            {
                cur_path = fs::current_path().remove_filename();
                fs::current_path(cur_path);
                cout << fs::current_path() << '\n';
            }
        }
        switch (key)
        {
        case 9:
            fs::create_directories("from");
            ofstream("from/file1.txt").put('a');
            fs::create_directory("to");
            fs::rename("from/file1.txt", "to/file2.txt");
            for (auto& p : fs::directory_iterator("to"))
            {
                cout << p.path() << '\n';
            }
            fs::remove_all("from");
            break;
        }
        switch (key)
        {
        case 10:
          
            fs::path p = fs::current_path() / "qwerty";
            fs::create_directories(p / "from");
            ofstream(p / "from/file1.txt").put('a');
            fs::create_directory(p / "to");      
            fs::rename(p / "from/file1.txt", p / "to/file2.txt");   
            fs::rename(p / "from", p / "to/subdir"); 

        }
        cout << "enter your key:" << '\n';
        cin >> key;
    }
    return 0;
}

    
    



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
