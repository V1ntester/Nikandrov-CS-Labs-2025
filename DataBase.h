class DataBase {
    private:
        char* fileName;
    public:
        DataBase();
        ~DataBase();

        void ReadDataBaseFromFile();
        void WriteDataBaseToFile();
        void SortDataBase();
        void AddToDataBase();
        void DeleteFromDataBase();
        void PrintDataBase();
};
