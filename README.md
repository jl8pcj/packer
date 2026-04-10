

<h1>入出力対応表</h1>



<body>



&#x20; <!-- A0〜A3 ミラー出力 -->

&#x20; <table>

&#x20;   <caption>A0〜A3 入力とミラー出力対応</caption>

&#x20;   <tr>

&#x20;     <th>入力ピン</th>

&#x20;     <th>ボタン動作</th>

&#x20;     <th>出力ピン</th>

&#x20;     <th>出力名</th>

&#x20;     <th>動作内容</th>

&#x20;   </tr>

&#x20;   <tr>

&#x20;     <td>A0</td>

&#x20;     <td>押す（LOW）</td>

&#x20;     <td>D2, D12</td>

&#x20;     <td>sol4A</td>

&#x20;     <td>HIGH（反転ミラー）</td>

&#x20;   </tr>

&#x20;   <tr>

&#x20;     <td>A1</td>

&#x20;     <td>押す（LOW）</td>

&#x20;     <td>D3, D12</td>

&#x20;     <td>sol910</td>

&#x20;     <td>HIGH（反転ミラー）</td>

&#x20;   </tr>

&#x20;   <tr>

&#x20;     <td>A2</td>

&#x20;     <td>押す（LOW）</td>

&#x20;     <td>D4, D12</td>

&#x20;     <td>sol3A</td>

&#x20;     <td>HIGH（反転ミラー）</td>

&#x20;   </tr>

&#x20;   <tr>

&#x20;     <td>A3</td>

&#x20;     <td>押す（LOW）</td>

&#x20;     <td>D5, D12</td>

&#x20;     <td>sol3B</td>

&#x20;     <td>HIGH（反転ミラー）</td>

&#x20;   </tr>

&#x20; </table>



&#x20; <!-- A4 → D10 ロック -->

&#x20; <table>

&#x20;   <caption>A4 入力と D10 ロック動作</caption>

&#x20;   <tr>

&#x20;     <th>入力ピン</th>

&#x20;     <th>トリガ条件</th>

&#x20;     <th>出力ピン</th>

&#x20;     <th>出力名</th>

&#x20;     <th>動作内容</th>

&#x20;   </tr>

&#x20;   <tr>

&#x20;     <td>A4</td>

&#x20;     <td>押した瞬間（HIGH → LOW）</td>

&#x20;     <td>D10</td>

&#x20;     <td>sol4B</td>

&#x20;     <td>0.5秒後に ON、2秒経過で自動 OFF</td>

&#x20;   </tr>

&#x20; </table>



&#x20; <!-- A5 → シーケンス制御 -->

&#x20; <table>

&#x20;   <caption>A5 入力とシーケンス制御</caption>

&#x20;   <tr>

&#x20;     <th>入力ピン</th>

&#x20;     <th>操作</th>

&#x20;     <th>動作</th>

&#x20;   </tr>

&#x20;   <tr>

&#x20;     <td>A5</td>

&#x20;     <td>押して離す</td>

&#x20;     <td>停止状態 → シーケンス開始</td>

&#x20;   </tr>

&#x20;   <tr>

&#x20;     <td>A5</td>

&#x20;     <td>押して離す</td>

&#x20;     <td>実行中 → 一時停止</td>

&#x20;   </tr>

&#x20;   <tr>

&#x20;     <td>A5</td>

&#x20;     <td>押して離す</td>

&#x20;     <td>一時停止 → 再開</td>

&#x20;   </tr>

&#x20; </table>



&#x20; <!-- シーケンス詳細 -->

&#x20; <table>

&#x20;   <caption>シーケンス出力（D6〜D9, D12）</caption>

&#x20;   <tr>

&#x20;     <th>ステップ</th>

&#x20;     <th>出力ピン</th>

&#x20;     <th>出力名</th>

&#x20;     <th>時間</th>

&#x20;     <th>内容</th>

&#x20;   </tr>

&#x20;   <tr>

&#x20;     <td>0</td>

&#x20;     <td>D6, D12</td>

&#x20;     <td>seq1, accel</td>

&#x20;     <td>2秒</td>

&#x20;     <td>ON → OFF</td>

&#x20;   </tr>

&#x20;   <tr>

&#x20;     <td>1</td>

&#x20;     <td>なし</td>

&#x20;     <td>休止</td>

&#x20;     <td>0.3秒</td>

&#x20;     <td>待機</td>

&#x20;   </tr>

&#x20;   <tr>

&#x20;     <td>2</td>

&#x20;     <td>D7, D12</td>

&#x20;     <td>seq2, accel</td>

&#x20;     <td>2秒</td>

&#x20;     <td>ON → OFF</td>

&#x20;   </tr>

&#x20;   <tr>

&#x20;     <td>3</td>

&#x20;     <td>なし</td>

&#x20;     <td>休止</td>

&#x20;     <td>0.3秒</td>

&#x20;     <td>待機</td>

&#x20;   </tr>

&#x20;   <tr>

&#x20;     <td>4</td>

&#x20;     <td>D8, D12</td>

&#x20;     <td>seq3, accel</td>

&#x20;     <td>2秒</td>

&#x20;     <td>ON → OFF</td>

&#x20;   </tr>

&#x20;   <tr>

&#x20;     <td>5</td>

&#x20;     <td>なし</td>

&#x20;     <td>休止</td>

&#x20;     <td>0.3秒</td>

&#x20;     <td>待機</td>

&#x20;   </tr>

&#x20;   <tr>

&#x20;     <td>6</td>

&#x20;     <td>D9, D12</td>

&#x20;     <td>seq4, accel</td>

&#x20;     <td>2秒</td>

&#x20;     <td>ON → OFF（シーケンス終了）</td>

&#x20;   </tr>

&#x20; </table>



</body>

</html>
