package round1;

import java.util.Arrays;
import java.util.Scanner;

/**
 * @Author: JQY
 * @Date: 2023-02-08 02:48:06
 * @Description:
 */
public class Resolution1003 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), m = scanner.nextInt(), start = scanner.nextInt(), end = scanner.nextInt();
        int numberOfRescueTeams[] = new int[n], roadLengths[][] = new int[n][n];
        boolean visit[] = new boolean[n];//访问标记
        Arrays.fill(visit, false);
        int dis[] = new int[n];//距离
        Arrays.fill(dis, -1);
        int roadNum[] = new int[n];//最短路径的条数
        Arrays.fill(roadNum, 0);
        int teamNum[] = new int[n];//最多可找到的救援队的数量
        Arrays.fill(teamNum, 0);
        for (int i = 0; i < n; i++) {
            Arrays.fill(roadLengths[i], -1);
        }
        for (int i = 0; i < n; i++) {
            numberOfRescueTeams[i] = scanner.nextInt();
        }
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt(), b = scanner.nextInt();
            roadLengths[a][b] = scanner.nextInt();
            roadLengths[b][a] = roadLengths[a][b];
            if (a == start) {
                dis[b] = roadLengths[a][b];
            }
            if (b == start) {
                dis[a] = roadLengths[b][a];
            }
        }
        //开始处理
        dis[start] = 0;
        teamNum[start] = numberOfRescueTeams[start];
        roadNum[start] = 1;
        for (int i = 0; i < n; i++) {
            int u = -1, minn = 0;
            for (int j = 0; j < n; j++) {
                if (!visit[j] && dis[j] != -1 && (u == -1 || dis[j] < minn)) {
                    u = j;
                    minn = dis[j];
                }
            }
            if (u == -1) break;
            visit[u] = true;
            for (int v = 0; v < n; v++) {
                if (!visit[v] && roadLengths[u][v] != -1) {
                    if (dis[u] + roadLengths[u][v] < dis[v] || dis[v] == -1) {
                        dis[v] = dis[u] + roadLengths[u][v];
                        roadNum[v] = roadNum[u];
                        teamNum[v] = teamNum[u] + numberOfRescueTeams[v];
                    } else if (dis[u] + roadLengths[u][v] == dis[v]) {
                        roadNum[v] = roadNum[v] + roadNum[u];
                        if (teamNum[u] + numberOfRescueTeams[v] > teamNum[v])
                            teamNum[v] = teamNum[u] + numberOfRescueTeams[v];
                    }
                }
            }
        }
        System.out.printf("%d %d", roadNum[end], teamNum[end]);
    }
}
