var countMentions = function (numberOfUsers, events) {
  events.sort((a, b) => {
    const timeA = parseInt(a[1]);
    const timeB = parseInt(b[1]);
    if (timeA !== timeB) {
      return timeA - timeB;
    }
    return (a[0] === "OFFLINE" ? -1 : 0) - (b[0] === "OFFLINE" ? -1 : 0);
  });

  const count = new Array(numberOfUsers).fill(0);
  const nextOnlineTime = new Array(numberOfUsers).fill(0);

  for (const event of events) {
    const curTime = parseInt(event[1]);
    const type = event[0];

    if (type === "MESSAGE") {
      const target = event[2];
      if (target === "ALL") {
        for (let i = 0; i < numberOfUsers; i++) {
          count[i]++;
        }
      } else if (target === "HERE") {
        for (let i = 0; i < numberOfUsers; i++) {
          if (nextOnlineTime[i] <= curTime) {
            count[i]++;
          }
        }
      } else {
        const users = target.split(" ");
        for (const user of users) {
          const idx = parseInt(user.substring(2));
          count[idx]++;
        }
      }
    } else {
      const idx = parseInt(event[2]);
      nextOnlineTime[idx] = curTime + 60;
    }
  }

  return count;
};
