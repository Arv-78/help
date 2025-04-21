/*
    author: arv
*/
#include <bits/stdc++.h>
using namespace std;

// print possible keynotes for given chromatic notes
// calculate - major scale for each chromatic note as key note
// check if all given notes are present in major scale of notes


// Range of audible frequencies divided into octaves

/**
 * octave = 13 chromatic notes 
 * 
 * y yx yx^2 yx^3 ... yx^12 = 2y
 * 
 * yx^12 = 2y; 
 * x^12 = 2;
 * x = root(2, 12)
 * x = 1.0593;
 * 
 * separation between two chromatic notes = semi-tone / half-step
 * 
 * chromatic scale : C, C#, D, D#, E, F, F#, G, G#, A, A#, B, C
 * 
 * major scale - 8 notes separated by: tone, tone, semi-tone, tone, tone, tone, semi-tone
 * first note is key of the scale
 * e.g., if C is key then major scale: C, D, E, F, G, A, B, C; if F is key then: F, G, A, A#, C, D, E, F
 * 
 */

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    vector <string> chromatic_notes = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    vector <int> major_scale_sep = {0, 2, 2, 1, 2, 2, 2, 1};

    unordered_map <string, vector<string>> major_scales;
    string input_seq;
    unordered_map <string, int> wannabe_keynotes;

    // calculates all major scales considering all notes as keynotes
    for(int be_keynote = 0; be_keynote < 12; be_keynote++){
        int temp = be_keynote;
        string keynote = chromatic_notes[temp];

        for(int sep : major_scale_sep){
            temp += sep;
            major_scales[keynote].push_back(chromatic_notes[temp % 12]);
        }

    }
    
    // unordered_map <string, vector<string>>:: iterator it = major_scales.begin();

    // for(; it != major_scales.end(); ++it){
    //     printf("%s -> ", it -> first.c_str());

    //     for(auto& note: it -> second){
    //         printf("%s ", note.c_str());
    //     }
    //     printf("\n");
    // }
    while(getline(cin, input_seq)){

        if(input_seq == "END") break;
        
        for(string& note1 : chromatic_notes){
            wannabe_keynotes[note1] = 1;
        }

        // for(auto& pair: wannabe_keynotes){
        //     printf("%s -> %d\n", pair.first.c_str(), pair.second);
        // }

        // check if each note is present in the wannabe keynote
        stringstream i_notes(input_seq);
        string i_note;
        while(i_notes >> i_note){
            for(auto& pair: major_scales){
                bool is_present = false;
                if(wannabe_keynotes[pair.first]) // if it is a keynote
                for(auto& note2: pair.second){
                    if(note2 == i_note){
                        is_present = true;
                    }
                }

                if(!is_present) wannabe_keynotes[pair.first] = 0;
    
            }
        }
        int use_sep = 0;
        for(auto& note: chromatic_notes){
            if(wannabe_keynotes[note]){
                if(use_sep) printf(" ");
                use_sep = 1;
                printf("%s", note.c_str());
            }
        }
        printf("\n");
    }



    return 0;
}