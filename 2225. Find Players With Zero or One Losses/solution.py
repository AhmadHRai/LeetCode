""" 
Hashmap Counting

    Initialize lostZero to all winners.
    Initialize lostOne as a empty list
    Count the number of matches he/she lost.
    Remove from lostZero if one lost a match.
    Append to lostOne if one lost exactly one match.
    Sort both lists and return

Time Complexity: O(NlogN), the most time consuming part is to sort the lostZero and lostOne, which is NlogN.
"""

class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        # Convert matches to [[winner, winner, ...], [loser, loser, ...]]
        wl = list(zip(*matches))
        
        # Initialize lostZero to all winners.
        # We will remove a winner if he/she loses a match.
        lostZero = set(wl[0])
        
        # We will append if he/she lost exactly one match.
        lostOne = []
        
        # count the number of matches he/she losts.
        countLost = Counter(wl[1])
        
        
        for key in countLost.keys():
            # Remove a winner if he/she lost a match.
            if countLost[key] > 0 and key in lostZero: lostZero.remove(key)
            # Append if he/she lost exactly one match.
            if countLost[key] == 1: lostOne.append(key)
        
        # Sort the two lists before return
        return [sorted(list(lostZero)),sorted(lostOne)]

""" 
Counting Sort

    Using a list players with the length of maximum player ID + 1 to represent if a player never lost any game (players[i] will be 1) or lost excatly one game (players[i] will be -1).
    for each match:
    (1) if the winner never lost before, set it to 1.
    (2) if the loser has lost before, decrease it by 1.
    (3) if the loser never lost before, set it to -1.
    Now we just need to go through players one more time to collect the player id and append them to lostZero and lostOne.
    Note that since the player ID is just the index in players, they are already sorted. (Counting sort)

TC: O(n+m), where m is the maximum playerID.
 """

class Solution2:
    def findWinners2(self, matches: List[List[int]]) -> List[List[int]]:
        n = max(chain(*matches))+1
        players = [0] * n
        for w, l in matches:
            if players[w]>=0: players[w]=1      # (1)
            if players[l]<0: players[l]-=1      # (2)
            if players[l]>=0: players[l]=-1     # (3)
        
        # Collect players' id.
        lostZero,lostOne = [],[]
        for i in range(n):
            if players[i] == 1:
                lostZero.append(i)
            elif players[i] == -1:
                lostOne.append(i)
        
        # They are already sorted
        return [lostZero,lostOne]