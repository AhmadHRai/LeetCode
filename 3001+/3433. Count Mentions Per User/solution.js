/**
 * @param {number} numberOfUsers
 * @param {string[][]} events
 * @return {number[]}
 */
var countMentions = function (numberOfUsers, events) {
  const mentions = new Array(numberOfUsers).fill(0);

  // Track offline periods: Map<userId, List<{start, end}>>
  const offlinePeriods = new Map();
  for (let i = 0; i < numberOfUsers; i++) {
    offlinePeriods.set(i, []);
  }

  // First pass: collect all offline periods
  for (const event of events) {
    if (event[0] === "OFFLINE") {
      const timestamp = parseInt(event[1]);
      const userId = parseInt(event[2]);
      const endTime = timestamp + 60;
      offlinePeriods.get(userId).push({ start: timestamp, end: endTime });
    }
  }

  // Second pass: process events in order
  for (const event of events) {
    const timestamp = parseInt(event[1]);

    if (event[0] === "MESSAGE") {
      const mentionsStr = event[2];
      const tokens = mentionsStr.split(" ");

      for (const token of tokens) {
        if (token === "ALL") {
          // Mention all users
          for (let i = 0; i < numberOfUsers; i++) {
            mentions[i]++;
          }
          break;
        } else if (token === "HERE") {
          // Mention all online users
          for (let i = 0; i < numberOfUsers; i++) {
            const isOnline = isUserOnline(i, timestamp, offlinePeriods);
            if (isOnline) {
              mentions[i]++;
            }
          }
          break;
        } else if (token.startsWith("id")) {
          // Direct mention of specific user
          const userId = parseInt(token.slice(2));
          if (userId >= 0 && userId < numberOfUsers) {
            mentions[userId]++;
          }
        }
      }
    }
    // OFFLINE events processed in first pass
  }

  return mentions;
};

// Helper function to check if user is online at given timestamp
function isUserOnline(userId, timestamp, offlinePeriods) {
  const periods = offlinePeriods.get(userId);
  for (const period of periods) {
    if (timestamp >= period.start && timestamp < period.end) {
      return false;
    }
  }
  return true;
}
