int main()
{
    TreeNode *root = nullptr;
    char choice;

    do
    {
        peminjaman(root);
        cout << "Apakah Anda ingin memasukkan data lagi? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}