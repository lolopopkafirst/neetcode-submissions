class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> us;

        // ИЗМЕНЕНИЕ 1: Используем вектор пар вместо словаря, 
        // чтобы не терять одинаковые строки (дубликаты)
        vector<pair<string, unordered_map<char, int>>> um;
        
        for(string str : strs){
            unordered_map <char, int> count;
            for(char ch : str){
                count[ch]++;
            }
            // Просто добавляем в конец вектора
            um.push_back({str, count}); 
        }

        // ИЗМЕНЕНИЕ 2: Используем массив флагов вместо вектора seen.
        // Это надежнее и быстрее.
        vector<bool> seen(um.size(), false); 

        // Идем по ИНДЕКСАМ, чтобы понимать, где какой элемент
        for(int i = 0; i < um.size(); i++){
            if(!seen[i]){ // Если мы еще не забрали это слово в какую-то группу
                vector<string> res = {um[i].first};
                seen[i] = true;
                
                // Ищем пару только среди ТЕХ ЭЛЕМЕНТОВ, ЧТО ИДУТ ДАЛЬШЕ (j = i + 1)
                // Это заменяет твою проверку str1 != str и спасает от дубликатов
                for(int j = i + 1; j < um.size(); j++){
                    if(!seen[j]){
                        if(um[i].first.size() == um[j].first.size()){
                            // Сравниваем внутренние словари частот
                            if(um[i].second == um[j].second) {
                                res.push_back(um[j].first);
                                seen[j] = true;
                            }
                        }
                    }
                }
                us.push_back(res);
            }
        }
        return us;
    }
};