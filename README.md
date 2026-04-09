<!DOCTYPE html>
<html lang="ja">
<head>
  <meta charset="UTF-8">
  <title>入出力対応表</title>
  <style>
    table { border-collapse: collapse; margin: 12px 0; }
    th, td { border: 1px solid #555; padding: 4px 8px; }
    th { background: #eee; }
    caption { font-weight: bold; margin-bottom: 4px; }
  </style>
</head>
<body>

  <!-- A0〜A3 ミラー出力 -->
  <table>
    <caption>A0〜A3 入力とミラー出力対応</caption>
    <tr>
      <th>入力ピン</th>
      <th>ボタン動作</th>
      <th>出力ピン</th>
      <th>出力名</th>
      <th>動作内容</th>
    </tr>
    <tr>
      <td>A0</td>
      <td>押す（LOW）</td>
      <td>D2</td>
      <td>sol4A</td>
      <td>HIGH（反転ミラー）</td>
    </tr>
    <tr>
      <td>A1</td>
      <td>押す（LOW）</td>
      <td>D3</td>
      <td>sol910</td>
      <td>HIGH（反転ミラー）</td>
    </tr>
    <tr>
      <td>A2</td>
      <td>押す（LOW）</td>
      <td>D4</td>
      <td>sol3A</td>
      <td>HIGH（反転ミラー）</td>
    </tr>
    <tr>
      <td>A3</td>
      <td>押す（LOW）</td>
      <td>D5</td>
      <td>sol3B</td>
      <td>HIGH（反転ミラー）</td>
    </tr>
  </table>

  <!-- A4 → D10 ロック -->
  <table>
    <caption>A4 入力と D10 ロック動作</caption>
    <tr>
      <th>入力ピン</th>
      <th>トリガ条件</th>
      <th>出力ピン</th>
      <th>出力名</th>
      <th>動作内容</th>
    </tr>
    <tr>
      <td>A4</td>
      <td>押した瞬間（HIGH → LOW）</td>
      <td>D10</td>
      <td>sol4B</td>
      <td>0.5秒後に ON、2秒経過で自動 OFF</td>
    </tr>
  </table>

  <!-- A5 → シーケンス制御 -->
  <table>
    <caption>A5 入力とシーケンス制御</caption>
    <tr>
      <th>入力ピン</th>
      <th>操作</th>
      <th>動作</th>
    </tr>
    <tr>
      <td>A5</td>
      <td>押して離す</td>
      <td>停止状態 → シーケンス開始</td>
    </tr>
    <tr>
      <td>A5</td>
      <td>押して離す</td>
      <td>実行中 → 一時停止</td>
    </tr>
    <tr>
      <td>A5</td>
      <td>押して離す</td>
      <td>一時停止 → 再開</td>
    </tr>
  </table>

  <!-- シーケンス詳細 -->
  <table>
    <caption>シーケンス出力（D6〜D9, D12）</caption>
    <tr>
      <th>ステップ</th>
      <th>出力ピン</th>
      <th>出力名</th>
      <th>時間</th>
      <th>内容</th>
    </tr>
    <tr>
      <td>0</td>
      <td>D6, D12</td>
      <td>seq1, accel</td>
      <td>2秒</td>
      <td>ON → OFF</td>
    </tr>
    <tr>
      <td>1</td>
      <td>なし</td>
      <td>休止</td>
      <td>0.3秒</td>
      <td>待機</td>
    </tr>
    <tr>
      <td>2</td>
      <td>D7, D12</td>
      <td>seq2, accel</td>
      <td>2秒</td>
      <td>ON → OFF</td>
    </tr>
    <tr>
      <td>3</td>
      <td>なし</td>
      <td>休止</td>
      <td>0.3秒</td>
      <td>待機</td>
    </tr>
    <tr>
      <td>4</td>
      <td>D8, D12</td>
      <td>seq3, accel</td>
      <td>2秒</td>
      <td>ON → OFF</td>
    </tr>
    <tr>
      <td>5</td>
      <td>なし</td>
      <td>休止</td>
      <td>0.3秒</td>
      <td>待機</td>
    </tr>
    <tr>
      <td>6</td>
      <td>D9, D12</td>
      <td>seq4, accel</td>
      <td>2秒</td>
      <td>ON → OFF（シーケンス終了）</td>
    </tr>
  </table>

</body>
</html>
