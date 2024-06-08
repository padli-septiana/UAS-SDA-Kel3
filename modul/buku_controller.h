#ifndef CONTROLLER_BUKU_H
#define CONTROLLER_BUKU_H

#include <iostream>
#include "../data/buku.h"

using namespace std;

void insert_buku(Buku data)
{
    treeBuku *newBook = new treeBuku;
    newBook->data = data;
    newBook->left = NULL;
    newBook->right = NULL;

    if (pohonBuku == NULL)
    {
        pohonBuku = newBook;
        rootBuku = newBook;
    }
    else
    {
        treeBuku *current = pohonBuku;
        treeBuku *parent = NULL;

        while (true)
        {
            parent = current;

            if (data.id < current->data.id)
            {
                current = current->left;

                if (current == NULL)
                {
                    parent->left = newBook;
                    return;
                }
            }
            else
            {
                current = current->right;

                if (current == NULL)
                {
                    parent->right = newBook;
                    return;
                }
            }
        }
    }
}

void show_list_buku(treeBuku *root)
{
    if (root != NULL)
    {
        cout << root->data.id << ". " << root->data.judul << " - " << root->data.status << "\n";
        show_list_buku(root->left);
        show_list_buku(root->right);
    }
}

// void findTree(tree **root, int cari)
// {
//     int level = 0;
//     tree *temp;
//     temp = new tree;
//     temp = (*root);

//     while (temp != NULL)
//     {
//         level++;
//         if (temp->data == cari)
//         {
//             cout << "Data " << cari << " ditemukan" << endl;
//             return;
//         }
//         else if (cari < temp->data)
//         {
//             temp = temp->left;
//         }
//         else
//         {
//             temp = temp->right;
//         }
//     }

//     cout << "data " << cari << " tidak ditemukan" << endl;
//     return;
// }

Buku find_id_buku(treeBuku **root, int id)
{
    int level = 0;
    treeBuku *temp = *root;

    while (temp != NULL)
    {
        level++;
        if (temp->data.id == id)
        {
            return temp->data;
        }
        else if (id < temp->data.id)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    cout << "data tidak ditemukan" << endl;
    return {};
}

void insert_books()
{
    insert_buku(data_buku1);
    insert_buku(data_buku2);
    insert_buku(data_buku3);
    insert_buku(data_buku4);
    insert_buku(data_buku5);
    insert_buku(data_buku6);
    insert_buku(data_buku7);
    insert_buku(data_buku8);
    insert_buku(data_buku9);
    insert_buku(data_buku10);
}
#endif