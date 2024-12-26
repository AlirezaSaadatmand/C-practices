#include <stdio.h>
#include <stdlib.h>
#include "cJSON/cJSON.h"

int main() {
    // Create a JSON object
    cJSON *root = cJSON_CreateObject();

    // Add data to the JSON object
    cJSON_AddStringToObject(root, "name1", "John");
    cJSON_AddNumberToObject(root, "age", 30);
    cJSON_AddBoolToObject(root, "is_student", 0);

    // Convert JSON object to a string
    char *json_string = cJSON_Print(root);

    // Save JSON string to a file
    FILE *file = fopen("output.json", "w");
    if (file == NULL) {
        perror("Failed to open file");
        cJSON_Delete(root);
        free(json_string);
        return 1;
    }
    fprintf(file, "%s", json_string);
    fclose(file);

    // Free allocated memory
    cJSON_Delete(root);
    free(json_string);

    return 0;
}
