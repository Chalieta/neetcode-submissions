class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int result = students.size();
        queue<int> q;

        for (int student : students) {
            q.push(student);
        }

        for (int sandwich : sandwiches) {
            int count = 0;
            // Loop ends after 1 circle or when sandwich matches preference
            while (count < students.size() && q.front() != sandwich) {
                q.push(q.front());
                q.pop();
                count++;
            }

            if (q.front() == sandwich) {
                q.pop();
                result--;
            } else {
                break;
            }
        }

        return result;
    }
};