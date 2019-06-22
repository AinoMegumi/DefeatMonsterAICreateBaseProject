# DefeatMonsterAICreateBaseProject
モンスター討伐ゲーム　アンチ核家族化のAIの制作用基本プロジェクト

## AIの作り方
1. dllの名前をパートナーキャラクターやモンスターの識別タグと同じ名前にする
1. AI.defのLIBRARYの名前を上記と同じ名前にする
1. モンスターの場合はOffline::ExternalEnemyAIとOnline::ExternalEnemyAI、パートナーの場合はOffline::ExternalPartnerAIとOnline::ExternalPartnerAIをpublic継承するクラスをそれぞれ作成する
1. GetOfflineExternalAI関数とGetOnlineExternalAI関数を完成させる

## コマンドの発行方法
発行できるコマンドは、次の通りです。

- 通常攻撃
- 魔法
- 防御

発行したいコマンドをoverrideしたcommand関数の戻り値とすることで、コマンドを発行できます。

### 通常攻撃をしたい場合
Skillクラスの変数を定義し、Tagメンバー変数の値を"amnormal"でコマンドを発行してください。

### ガードしたい場合
Skillクラスの変数を定義し、Tagメンバー変数の値を"amguard"でコマンドを発行してください。

※モンスターでガードコマンドを発行すると、泣かせになってしまうのでなるべく控えてください

### 魔法攻撃をしたい場合

command関数の引数からパラメーターと、使える魔法の一覧が与えられます。

攻撃魔法はAbleToUseAttackMagicに格納されていますのでこの中から選択して下さい。

### 回復をしたい場合

単体回復魔法はAbleToSingleCureMagic、範囲回復魔法はAbleToRangeCureMagicに格納されていますのでこの中から選択して下さい。

ただし、モンスターはAbleToRangeCureMagicは空っぽです。

## キャラクターの配列上の場所(固定)
### オフライン
0: プレイヤー

1: 第１パートナー

2: 第２パートナー

3: 敵

### オンライン
0: プレイヤー１(ルーム開設者)

1: プレイヤー２(ルーム参加者)

2: 第１パートナー

3: 第２パートナー

4: 敵

## 作成時の注意事項
- 実装用に固有に実装する関数は自由に実装していただいて構いませんが、command関数とGetCureTarget関数(パートナー)とGetAttackTarget関数(モンスター)はnoexceptにして下さい
- オンライン限定AIを作る場合はGetOfflineExternalAI関数、オフライン限定AIを作る場合はGetOnlineExternalAI関数を削除して下さい。ただし、限定AIを実装した場合、もう一方はクライアント内に組み込まれているAIが使われます
- パートナーのAIを実装する場合は、ExternalAI.hppより上で"MAKE\_PARTNER\_AI"マクロを定義する必要があります
- AIは必ずご自身で動作テストを行ったうえで公開して下さい
