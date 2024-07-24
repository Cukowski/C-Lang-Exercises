#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

typedef struct {
    char atom[3];
    int count;
} atom_count_t;

int compare_atoms(const void* a, const void* b);
void print_atoms(atom_count_t* atoms);

atom_count_t* number_of_atoms_struct(char* param_1)
{
    // Dynamically allocate memory for atoms array
    atom_count_t* atoms = malloc(MAX_LEN * sizeof(atom_count_t));
    if (atoms == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    int num_atoms = 0;
    int i = 0;

    // Initialize counts to zero
    for (int j = 0; j < MAX_LEN; j++) {
        atoms[j].count = 0;
    }

    // get the atoms from the input
    while (param_1[i]) 
    {
        if (param_1[i] >= 'A' && param_1[i] <= 'Z') // check if an element
        {
            if (param_1[i + 1] >= 'a' && param_1[i + 1] <= 'z') 
            {
                // two letter element
                atoms[num_atoms].atom[0] = param_1[i];
                atoms[num_atoms].atom[1] = param_1[i + 1];
                atoms[num_atoms].atom[2] = '\0';
                i += 2;
            } 
            else 
            {
                // one letter element
                atoms[num_atoms].atom[0] = param_1[i];
                atoms[num_atoms].atom[1] = '\0';
                i++;
            }
            
            // Count
            atoms[num_atoms].count = 0;

            // counting the numbers occur after the element
            while (param_1[i] >= '0' && param_1[i] <= '9')
            {
                atoms[num_atoms].count = atoms[num_atoms].count * 10 + (param_1[i] - '0');
                i++;
            }
            // even there is no number after, there is 1 of each element written
            if (atoms[num_atoms].count == 0)
            {
                atoms[num_atoms].count = 1;
            }

            num_atoms++;
        } 
        else if (param_1[i] == '(') // if there is a parenthesis
        {
            int j = i;
            // find the matching closing parenthesis
            int open_count = 0;
            while (param_1[j] != '\0') 
            {
                if (param_1[j] == '(') {
                    open_count++;
                } else if (param_1[j] == ')') {
                    open_count--;
                    if (open_count == 0) {
                        break;
                    }
                }
                j++;
            }

            // recursively parse the sub-formula inside the parenthesis
            atom_count_t* sub_atoms = number_of_atoms_struct(param_1 + i + 1);

            // Find the multiplier
            int multiplier = 0;
            j++;
            while (param_1[j] >= '0' && param_1[j] <= '9')
            {
                multiplier = multiplier * 10 + (param_1[j] - '0');
                j++;
            }
            if (multiplier == 0) {
                multiplier = 1;
            }

            // Update counts accordingly
            for (int k = 0; k < MAX_LEN; k++) 
            {
                if (sub_atoms[k].count > 0) 
                {
                    bool found = false;
                    for (int l = 0; l < num_atoms; l++) {
                        if (strcmp(atoms[l].atom, sub_atoms[k].atom) == 0) 
                        {
                            atoms[l].count += sub_atoms[k].count * multiplier;
                            found = true;
                            break;
                        }
                    }
                    if (!found) 
                    {
                        strcpy(atoms[num_atoms].atom, sub_atoms[k].atom);
                        atoms[num_atoms].count = sub_atoms[k].count * multiplier;
                        num_atoms++;
                    }
                }
            }

            // Update i to skip the parsed sub-formula
            i = j;
            
            free(sub_atoms);
        } 
        else 
        {
            i++;
        }
    }

    // Sort atoms alphabetically
    qsort(atoms, num_atoms, sizeof(atom_count_t), compare_atoms);

    return atoms;
}

// Function to compare atoms for sorting
int compare_atoms(const void* a, const void* b) {
    atom_count_t* atom_a = (atom_count_t*)a;
    atom_count_t* atom_b = (atom_count_t*)b;
    return strcmp(atom_a->atom, atom_b->atom);
}

// Function to print atoms with counts
void print_atoms(atom_count_t* atoms) {
    for (int i = 0; i < MAX_LEN; i++) {
        if (atoms[i].count > 0) {
            printf("atom: %s, count: %d\n", atoms[i].atom, atoms[i].count);
        }
    }
}

// Function to print atoms with counts and return the result as a string
char* atoms_to_string(atom_count_t* atoms) {
    char* result = (char*)malloc(50 * sizeof(char)); // Allocate memory for the result
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(result, ""); // Initialize result string
    for (int i = 0; i < MAX_LEN; i++) {
        if (atoms[i].count > 0) 
        {
            if(atoms[i].count == 1)
            {
                char atom_count[10]; // Buffer for each atom and its count
                sprintf(atom_count, "%s", atoms[i].atom);
                strcat(result, atom_count); // Concatenate to the result string
            }
            else
            {
                char atom_count[10]; // Buffer for each atom and its count
                sprintf(atom_count, "%s%d", atoms[i].atom, atoms[i].count);
                strcat(result, atom_count); // Concatenate to the result string
            }
        }
    }
    return result; // Return the final result
}

atom_count_t* merge_duplicates(atom_count_t* atoms) {
    // Create a new array to store merged atoms
    atom_count_t* merged_atoms = (atom_count_t*)malloc(MAX_LEN * sizeof(atom_count_t));
    if (merged_atoms == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    // Initialize counts to zero
    for (int i = 0; i < MAX_LEN; i++) {
        merged_atoms[i].count = 0;
    }

    // Process atoms array
    for (int i = 0; i < MAX_LEN; i++) {
        if (atoms[i].count > 0) {
            bool found = false;
            // Check if the atom already exists in the merged array
            for (int j = 0; j < MAX_LEN; j++) {
                if (strcmp(atoms[i].atom, merged_atoms[j].atom) == 0) {
                    // If found, update the count by adding the current count
                    merged_atoms[j].count += atoms[i].count;
                    found = true;
                    break;
                }
            }
            if (!found) {
                // If not found, add the atom to the merged array
                for (int j = 0; j < MAX_LEN; j++) {
                    if (merged_atoms[j].count == 0) {
                        strcpy(merged_atoms[j].atom, atoms[i].atom);
                        merged_atoms[j].count = atoms[i].count;
                        break;
                    }
                }
            }
        }
    }

    return merged_atoms;
}

char* number_of_atoms(char* param_1)
{
    atom_count_t* atoms = number_of_atoms_struct(param_1);

    atom_count_t* merged_atoms = merge_duplicates(atoms);

    char* result;
    result = atoms_to_string(merged_atoms);
    printf("%s\n", result);

    print_atoms(merged_atoms);
    
    free(atoms);
    free(merged_atoms); // Free the memory allocated for merged_atoms

    return result;
}

int main()
{
    // char formula[MAX_LEN] = "K4(ON(SO3)2)2";
    // char formula[MAX_LEN] = "Mg(OH)2";
    // char formula[MAX_LEN] = "H2O";
    // char formula[MAX_LEN] = "H11He49NO35B7N46Li20";
    char formula[MAX_LEN] = "((N42)24(OB40Li30CHe3O48LiNN26)33(C12Li48N30H13HBe31)21(BHN30Li26BCBe47N40)15(H5)16)14";
    // B18900Be18984C4200H5446He1386Li33894N50106O22638
    // B8316000Be192315900C6937350H342529600He34650Li114455250N282712962O565950
    // B8316000Be192315900C6937350H342529600He34650Li114455250N282712962O565950
    number_of_atoms(formula);

    return 0;
}
