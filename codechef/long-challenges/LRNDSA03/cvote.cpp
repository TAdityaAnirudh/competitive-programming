#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int main()
{
    int n;
    int m;
    int i;
    int j;
    int k;

    unordered_map<string, string> author_to_country;
    unordered_map<string, int> country_to_idx;
    unordered_map<string, int> author_to_idx;
    unordered_map<int, string> idx_to_author;
    unordered_map<int, string> idx_to_country;

    string author;
    string country;

    cin >> n >> m;

    j = 0;
    for (i = 0; i < n; i++)
    {
        cin >> author >> country;
        author_to_country[author] = country;
        author_to_idx[author] = i;
        idx_to_author[i] = author;

        if (country_to_idx.find(country) == country_to_idx.end())
        {
            country_to_idx[country] = j;
            idx_to_country[j] = country;
            j++;
        }
    }

    vector<int> author_votes(n, 0);
    vector<int> country_votes(j, 0);

    for (i = 0; i < m; i++)
    {
        cin >> author;
        j = author_to_idx[author];
        author_votes[j]++;

        k = country_to_idx[author_to_country[author]];
        country_votes[k]++;
    }

    // compute max author and country
    string final_author = "";
    string final_country = "";

    i = 0; // max votes per author
    j = 0; // max votes per country

    for (k = 0; k < n; k++)
    {
        if (author_votes[k] == i && idx_to_author[k] < final_author)
        {
            final_author = idx_to_author[k];
        }
        else if (author_votes[k] > i)
        {
            i = author_votes[k];
            final_author = idx_to_author[k];
        }
    }

    for (k = 0; k < idx_to_country.size(); k++)
    {
        if (country_votes[k] == j && idx_to_country[k] < final_country)
        {
            final_country = idx_to_country[k];
        }
        else if (country_votes[k] > j)
        {
            j = country_votes[k];
            final_country = idx_to_country[k];
        }
    }

    cout << final_country << "\n";
    cout << final_author << "\n";

    return 0;
}