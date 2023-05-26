// Firebase
#include <header.h>

void send24h()
{
    String timestamp;
    std::string databasePath = "/LogTest";

    if (Firebase.ready() && (millis() - sendDataPrevMillis > timerDelay || sendDataPrevMillis == 0))
    {
        sendDataPrevMillis = millis();

        while (!timeClient.update())
        {
            timeClient.forceUpdate();
        }
        // Get current timestamp
        timestamp = timeClient.getFormattedDate();
        timestamp.replace("T", " ");
        timestamp.replace("Z", "");
        char timeStr[9];
        char dateStr[11];
        sscanf(timestamp.c_str(), "%10s %8s", dateStr, timeStr);
        Serial.print("time: ");
        Serial.println(timestamp);

        std::string parentPath = databasePath + "/" + dateStr;

        if (percentage >= 100)
        {
            json.set(statusPath.c_str(), "FULL");
        }
        else
        {
            json.set(statusPath.c_str(), "AVAILABLE");
        }
        json.set(weightPath.c_str(), String(weight));
        json.set(percentPath.c_str(), String(percentage));
        json.set(datePath, String(dateStr));
        json.set(timePath, String(timeStr));

        Serial.printf("Set json... %s\n", Firebase.RTDB.setJSON(&firebaseData, parentPath.c_str(), &json) ? "ok" : firebaseData.errorReason().c_str());
    }
}

void realtimeSend()
{
    rts.set("/capacity", percentage);
    Firebase.updateNode(firebaseData, "/Read/Tong1", rts);
    rts.set("/weight1", weight);
    Firebase.updateNode(firebaseData, "/Read/Tong1", rts);
    delay(1000);
}

void setup_firebase()
{
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);

    Firebase.setReadTimeout(firebaseData, 1000 * 60);
    Firebase.setwriteSizeLimit(firebaseData, "tiny");
}