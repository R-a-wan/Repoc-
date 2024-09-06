#include <bits/stdc++.h>
#include<windows.h>
#include<dirent.h>
using namespace std;
namespace fs = std::filesystem;

vector<string> get_all_extension_files(string folder)
{

    vector<string>names;
    string search_path = folder+"/*.ext";
    WIN32_FIND_DATA fd;
    HANDLE hFind = ::FindFirstFile(search_path.c_str(),fd);
    if(hFind != INVALID_HANDLE_VALUE)
    {
        do{
            if(!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                names.pushback(fd.cFileName);
            }
        }while(::FindNextFile(hFind, &fd));
        ::FindClose(hFind);
    }
    return names;
}

int main()
{
    char folderName[1000];
    getline(cin, folderName);

    char Names[] = get_all_extension_files(folderName);

    error_code ec;
    fs::directory_iterator dir(Names, ec);

    char DirToText[] = mkdir("C:/project1/Ideas/");

    char DirToDocs[] = mkdir("C:/project1/Docs/");

    char DirToImgs[] = mkdir("C:/project1/Images/");

    char DirToData[] = mkdir("C:/project1/Data/");

    char DirToMu[] = mkdir("C:/project1/Multim/");

    char DirToOth[] = mkdir("C:/project1/Others/");

    for(const auto &d: dir)
    {
        if(d.path().extension() == ".txt" | d.path().extension() == ".md" ){

            fs::path fullPath = DirToText[].c_str();
            Fname = d.filename().c_str();
            fullPath /= Fname;
            if(rename(d.path(), fullPath.c_str()) == 0){
                 cout<<"This is a renamed text file : "<< fullPath.c_str()<<endl;
            }

        }
        else if(d.path().extension() == ".doc" | d.path().extension() == ".docs" | d.path().extension() == ".pdf" ){

            fs::path fullPath = DirToDocs[].c_str();
            Fname = d.filename().c_str();
            fullPath /= Fname;
            if(rename(d.path(), fullPath.c_str()) == 0){
                 cout<<"This is a renamed documents file : "<< fullPath.c_str()<<endl;
            }

        }
        if(d.path().extension() == ".jpg" | d.path().extension() == ".png" ){

            fs::path fullPath = DirToImgs[].c_str();
            Fname = d.filename().c_str();
            fullPath /= Fname;
            if(rename(d.path(), fullPath.c_str()) == 0){
                 cout<<"This is a renamed images file : "<< fullPath.c_str()<<endl;
            }

        }
        if(d.path().extension() == ".dat" | d.path().extension() == ".json" | d.path().extension() == ".csv"){

            fs::path fullPath = DirToData[].c_str();
            Fname = d.filename().c_str();
            fullPath /= Fname;
            if(rename(d.path().c_str(), fullPath.c_str()) == 0){
                 cout<<"This is a renamed text file : "<< fullPath.c_str()<<endl;
            }

        }

    }

    string newpath = "C:/project1/";

        cout<<"type Y if you want to change The Data folder name:\n";
            char ch;
            cin>>ch;
            if(ch == 'Y' | ch == 'y')
            {
                bool namedDa = false;
                cout<<"Enter the new name"<<endl;
                string newName;
                getline(cin,newName);

                string Datap = newpath / newName;

                if(rename(DirToData, Datap )){
                    namedDa = true;
                }

            }
            else{
                cout<<"Good\n";
            }

        cout<<"type Y if you want to change The Documents folder name:\n";

            cin>>ch;
            if(ch == 'Y' | ch == 'y')
            {
                bool namedDu = false;
                cout<<"Enter the new name"<<endl;

                getline(cin,newName);

                string Dup = newpath / newName;

                if(rename(DirToDocs, Dup )){
                    namedDu = true;
                }

            }
            else{
                cout<<"Good\n";
            }

        cout<<"type Y if you want to change The Text folder name:\n";

            cin>>ch;
            if(ch == 'Y' | ch == 'y')
            {
                bool namedT = false;
                cout<<"Enter the new name"<<endl;

                getline(cin,newName);

                string Tp = newpath / newName;

                if(rename(DirToText, Tp )){
                    namedT = true;
                }

            }
            else{
                cout<<"Good\n";
            }

        cout<<"type Y if you want to change The Images folder name:\n";

            cin>>ch;
            if(ch == 'Y' | ch == 'y')
            {
                bool namedI = false;
                cout<<"Enter the new name"<<endl;

                getline(cin,newName);

                string DataI = newpath / newName;

                if(rename(DirToData, DataI )){
                    namedI = true;
                }

            }
            else{
                cout<<"Good\n";
            }




    return 0;
}
