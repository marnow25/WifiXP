class IPSplitter {

public:
    void ipStringToArray(int* numbers, const char* ipString);
};

void IPSplitter::ipStringToArray(int* numbers, const char* ipString) {
    char buf[15];
    int i = 0;
    strcpy(buf, ipString);
    char *tokens = strtok(buf, ".");
    while (tokens) {
        numbers[i] = atoi(tokens);
        i++;
        tokens = strtok(NULL, ".");
    }
};