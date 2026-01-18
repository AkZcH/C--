class AuctionSystem {
public:
    unordered_map<int, unordered_map<int, int>>bids;
    unordered_map<int, set<pair<int, int>>>order;

    AuctionSystem() {}
    
    void addBid(int userId, int itemId, int bidAmount) {
        auto ind = make_tuple(userId, itemId, bidAmount);

        if (bids[itemId].count(userId)) {
            int oldAmount = bids[itemId][userId];
            order[itemId].erase({oldAmount, userId});
        }

        bids[itemId][userId] = bidAmount;
        order[itemId].insert({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        auto ind = make_tuple(userId, itemId, newAmount);

        int oldAmount = bids[itemId][userId];
        order[itemId].erase({oldAmount, userId});

        bids[itemId][userId] = newAmount;
        order[itemId].insert({newAmount, userId});
    }

    void removeBid(int userId, int itemId) {
        auto ind = make_pair(userId, itemId);

        int oldAmount = bids[itemId][userId];
        order[itemId].erase({oldAmount, userId});
        bids[itemId].erase(userId);

        if (bids[itemId].empty()) {
            bids.erase(itemId);
            order.erase(itemId);
        }
    }

    int getHighestBidder(int itemId) {
        auto ind = itemId;

        if (!order.count(itemId) || order[itemId].empty())
            return -1;

        return order[itemId].rbegin()->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */
