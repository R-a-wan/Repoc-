#include<bits/stdc++.h>
#include<filesystem>
#include<string>
#include<set>
#include<vector>

using namespace std;
namespace fs = std::filesystem;

string getFileType(const fs::path &files){

       string ext = files.extension().string();
       if(ext.size() > 1){
        return ext.substr(1);
       }
       return "miscellaneous";
}

void makeFolders(const fs::path &folder, const set<string>fileTypes){

     for(const auto &fileType : fileTypes){
        fs::path newFolder = folder / fileType;
        error_code ec;
        fs::create_directories(newFolder,ec);
        if(ec){
            cerr<<newFolder<<"Couldn't be created"<<endl;
        }
     }
}

void moveFiles(const vector<fs::path>&files, const fs::path &folder){

     for(const auto &file : files){
        error_code ec;
        fs::rename(file, folder / getFileType(file)/file.filename(),ec);

        if(ec)
        {
            cerr<<file<<"Couldn't be moved"<<endl;
        }
     }

}

/*void Rename(const vector<fs::path>&files){

     for()

}*/
int main()
{
    string dirname;
    cout<<"Enter a directory path to open (leave blank to quit):\n ";
    getline(cin,dirname);

    error_code ec;
    fs::directory_iterator dir(dirname, ec);
    fs::path dirPath(dirname);


    DIR *pd =0;
    pd = opendir(dirname.c_str());
    if(pd == NULL){
        cerr<<"invalid directory"<<endl;
    }

    vector<fs::path>files;
    set<string>fileTypes;
    try{
          for(const auto &entry : dir){
            fs::path file = entry.path();
            files.push_back(file);
            fileTypes.insert(getFileType(file));
        }

        makeFolders(dirname, fileTypes);
        moveFiles(files, dirname);


    }catch(const fs::filesystem_error &e){
           cerr<<"FILESYSTEM error: "<<e.what()<<endl;
           return 1;

    }


    return 0;
}


/*
int move(const string &oldPath, const string &newPath)
{
    const size_t pos = oldPath.find_last_of('\\');
    const string newPath = newDir + '\\'+ (pos == string::npos ? oldPath : oldPath.substr(pos));
    return rename(oldPath.c_str(), newPath.c_str());
}

*/

/*vector<string> get_all_extension_files(string folder)
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
*/
