#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Sound {
public:
    Sound(int h, int d) : height(h), duration(d) {}
    int height;
    int duration;
};

bool compareDuration(const Sound& a, const Sound& b) {
    return a.duration < b.duration;
}

int main() {
    vector<Sound> melody = { {1, 2}, {2, 3}, {3, 2}, {4, 1}, {5, 2}, {6, 3}, {7, 1} };
    sort(melody.begin(), melody.end(), compareDuration);
    vector<Sound> newMelody;
    int prevDuration = -1;
    for (auto& sound : melody) {
        if (sound.duration != prevDuration) {
            newMelody.push_back(sound);
            prevDuration = sound.duration;
        }
    }
    melody = newMelody;
    return 0;
}
