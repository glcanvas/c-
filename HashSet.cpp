class HashSet {
public:
    HashSet() {
        g.resize(kek + 97, vector<int>(5, 0));
        pointer.resize(kek + 97, 0);
        ppow[0] = 1;
        for (int i = 1; i < 30; i++) {
            ppow[i] = ((ppow[i - 1] * pw)) % mod;
        }
    }

    bool found(int key) {
        int hash = getHash(key);
        for (int i = 0; i < pointer[hash]; i++) {
            if (g[hash][i] == key) {
                return true;
            }
        }
        return false;
    }

    void insert(int key) {
        if (found(key)) {
            return;
        }
        int hash = getHash(key);

        if (pointer[hash] < g[hash].size()) {
            g[hash][pointer[hash]] = key;
        } else {
            g[hash].pb(key);
        }
        pointer[hash]++;

        return;
    }


    void del(int key) {
        int hash = getHash(key);
        int size = pointer[hash];
        int pos = -1;
        for (int i = 0; i < size; i++) {
            if (key == g[hash][i]) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            return;
        }
        for (int i = pos; i < size; i++) {
            g[hash][i] = g[hash][i + 1];
        }
        pointer[hash]--;
        return;
    }

private:
    int kek = 3000000;
    vector<vector<int> > g;
    vector<int> pointer;
    int pw = 97;
    int mod = kek + 97;
    int ppow[30];


    int getHash(int key) {
        string ss = to_string(key);
        int ans = 0;
        for (int i = 0; i < ss.size(); i++) {
            ans = ((ans + ((int) ss[i]) * ppow[i])) % mod;
        }
        return ans;
    }
};
