class TweetCounts {
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        tweet[tweetName][time]++;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int chunksize = freq == "minute"? 60 : freq == "hour" ? 3600 : 86400;
        vector<int>count((endTime - startTime)/chunksize +1);
        map<int,int> timecount = tweet[tweetName];
        
        auto l = timecount.lower_bound(startTime);
        auto r = timecount.upper_bound(endTime);

        for(auto i = l ; i!=r; i++)
        {
            int index = (i->first - startTime)/chunksize;
            count[index]+=i->second;
        }
        return count;
    }

    private:

     unordered_map<string, map<int,int>>tweet;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
