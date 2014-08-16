

// 静流ーフォンツを使用。
// 使いそうな日本語をグーグル先生に伺い、トップ 1000 程をペンタブで書き殴ったゴリ押し＆悪あがきクラス。目的は達するからよし。
// 静流ーフォンツに無い文字は、「？」で描画される。デバッグ時にはこのまま残し、ゲームの完成時に足りない文字のみを補う。

#include "Karakuri.h"

// ここが最大の悪あがきとも言える。文字をもう、とにかく勢いで数字化。
// 細かいことはいい。やれ。＜しかしあれはまだ・・・＜今使わずにいつ使うのだ

namespace sizurus_fonts{
    
    enum ten_flags{
        dakuten,
        handakuten,
        none,
    };

enum SizurusFontsName{
    刊,圧,掲,捨,秘,札,導,九,麻,傷,濁点,歯,清,七,晴,晩,継,犯,辞,環,列,含,暗,剣,盾,腕,輪,貰,冬,州,稼,酔,
    賀,恵,測,乙,腐,牛,互,療,到,里,延,払,誘,旦,純,富,裕,綺,忙,箱,隠,嘘,嫁,蔵,敗,菅,尾,湯,妙,角,丁,監,
    ン,ー,鍵括弧始,鍵括弧閉,括弧始,括弧閉,歓,購,右,左,触,乱,仮,慢,百,推,那,堂,草,華,微,疑,陽,揺,責,快,景,劇,課,礼,財,耳,
    セ,ソ,タ,チ,ツ,テ,ト,ナ,ニ,ヌ,ネ,ノ,ハ,ヒ,フ,ヘ,ホ,マ,ミ,ム,メ,モ,ヤ,ユ,ヨ,ラ,リ,ル,レ,ロ,ワ,ヲ,
    み,む,め,も,や,ゆ,よ,ら,り,る,れ,ろ,わ,を,ん,波線,吃驚,疑問,句点,ア,イ,ウ,エ,オ,カ,キ,ク,ケ,コ,サ,シ,ス,
    歴,あ,い,う,え,お,た,ち,つ,て,と,か,き,く,け,こ,さ,し,す,せ,そ,な,に,ぬ,ね,の,は,ひ,ふ,へ,ほ,ま,
    泉,隣,豆,条,荷,級,税,否,脳,統,弟,億,岩,康,板,模,暖,背,境,街,油,建,短,罪,衛,階,与,誌,胸,汚,暴,株,
    掛,労,筋,納,補,簡,江,造,浮,麗,秋,鼻,洋,就,施,弾,鬼,各,恥,抱,倍,渋,沖,五,略,算,寺,姿,伊,惑,志,票,
    適,森,片,独,雅,萌,夕,弱,並,混,積,囲,裏,講,席,退,妹,端,察,菜,児,史,染,賞,瞬,芸,額,究,軍,刻,鳥,舞,
    異,祭,授,仙,挙,印,夏,破,鉄,盛,紹,攻,鹿,極,暇,大,涙,押,図,源,類,漫,症,悲,側,整,甘,粉,担,索,稿,司,
    玉,星,奴,香,救,脱,弁,警,恐,両,具,辛,護,桜,丸,猫,卒,途,娘,池,省,製,禁,専,替,渡,庫,奈,八,袋,駄,険,
    協,案,枝,乳,許,象,処,迎,策,錬,給,働,証,枚,姉,管,査,血,比,官,静,喜,息,精,評,是,橋,緊,昔,辺,四,根,
    接,旅,武,迷,逆,門,詳,振,催,勢,困,吉,勤,守,路,怒,父,展,便,貴,佐,津,壊,韓,隊,答,吹,洗,移,研,域,輩,
    謝,客,河,倒,毛,充,販,改,提,師,頼,危,装,換,族,激,紙,銀,費,編,種,効,防,軽,節,修,御,医,材,逃,派,薬,
    越,遠,営,党,火,載,午,求,殺,徐,去,等,戸,健,府,況,企,撮,吸,率,邪,崎,響,差,為,誕,雑,凄,例,低,浜,撃,
    英,届,戻,松,程,形,勉,規,末,南,寄,申,室,冷,巻,共,宿,走,工,王,十,商,細,首,似,仲,探,任,権,識,示,突,
    郎,熱,園,髪,判,収,基,肉,型,談,減,光,打,兄,追,若,停,負,介,存,器,周,服,雨,訳,術,波,深,準,余,科,抜,
    影,赤,育,頃,値,焼,視,職,総,済,際,段,交,横,温,頂,習,助,布,絡,酒,係,茶,士,割,藤,婚,役,眼,離,青,呂,
    命,降,黒,絵,苦,阪,価,飛,区,系,局,村,城,務,備,井,携,昼,登,恋,興,満,義,避,館,版,我,千,失,沢,敵,居,
    号,設,氏,単,増,射,聴,幸,嬉,古,座,量,置,断,了,容,病,論,進,由,募,谷,母,岡,資,団,注,歳,春,住,故,米,
    飯,魔,構,拡,西,念,忘,非,普,説,害,個,帯,宮,投,怖,曜,馬,広,果,歩,駅,町,質,告,腹,希,院,件,遊,描,宅,
    速,字,太,像,態,他,親,得,反,超,験,演,土,消,爆,慣,嫌,雪,和,録,検,認,指,供,泣,石,試,彼,遅,治,復,呼,
    痛,有,皆,保,残,約,状,毎,観,伝,常,優,急,転,木,映,台,緒,格,乗,更,利,花,寒,完,議,制,計,組,曲,支,君,
    限,止,空,写,北,別,覚,散,引,万,政,丈,産,口,運,援,欲,半,疲,重,返,平,夢,望,在,久,声,絶,点,頭,参,勝,
    次,色,主,飲,素,加,選,音,向,流,川,直,込,落,式,眠,身,界,死,特,僕,海,調,難,配,足,週,必,然,歌,葉,都,
    問,位,教,休,線,題,表,法,戦,語,校,過,県,受,解,員,正,続,三,夫,顔,友,想,記,福,第,応,民,決,経,誰,被,
    連,天,神,島,道,二,達,立,世,切,読,始,文,頑,屋,数,侍,悪,着,信,集,男,品,昨,機,成,化,要,願,能,確,活,
    安,震,山,美,情,可,市,違,京,水,考,風,代,予,売,野,関,以,災,少,相,取,真,元,車,白,店,夜,番,公,現,強,
    心,先,田,使,仕,付,外,社,対,帰,近,放,不,送,内,書,小,張,面,同,多,料,終,早,所,初,結,円,起,朝,期,雷,
    当,力,変,理,度,的,場,良,開,部,物,原,実,様,体,通,報,金,買,家,味,長,持,性,愛,用,意,繰り返し,聞,俺,業,名,
    発,無,手,来,新,月,全,地,最,電,明,楽,合,感,目,食,話,作,動,寝,東,定,好,後,女,知,下,回,高,者,画,薄,
    年,思,捕,行,本,学,言,国,中,分,日,人,今,折,見,気,出,一,時,燃,生,間,笑,子,方,自,会,前,私,何,上,入,
    句読点,一点,が,ぎ,ぐ,げ,ご,ざ,じ,ず,ぜ,ぞ,だ,ぢ,づ,で,ど,ば,び,ぶ,べ,ぼ,ぱ,ぴ,ぷ,ぺ,ぽ,伸ばし棒,縦棒,円マーク,イコール,アンパサンド,
    陸,汗,詰,懐,委,羽,港,癒,厳,怪,券,宇,照,縺,繋,永,_燃,寂,泊,杯,幼,肌,閉,荒,争,悔,婦,才,己,刺,借,闘,
    祈,魚,標,林,博,留,憶,干,齢,兵,章,央,障,典,呟,診,伸,農,順,枠,詞,船,旧,即,豊,寿,也,宜,樹,_到,六,徒,
    シングルクォーテーション,ダブルクォーテーション,エー,ビー,シー,ディー,イー,エフ,ジー,エイチ,アイ,ジェイ,ケイ,エル,エム,エヌ,オー,ピー,キュー,アール,エス,ティー,ユー,ブイ,ダブリュー,エクス,ワイ,ゼット,四角括弧初め,四角括弧閉じ,ゼロ,イチ,
    スラッシュ,パーセント,ドル,シャープ,アスタリスク,プラス,マイナス,アットマーク,セミコロン,コロン,角括弧初め,角括弧終わり,ニー,サン,シイ,ゴオ,ロク,シチ,ハチ,キュウ,衣,既,坊,房,臭,酷,秒,養,腰,滅,姫,_輪,
    庭,勘,茨,廃,握,露,功,骨,妻,領,勇,倉,老,巨,創,壁,掃,奇,咲,跡,_剣,誤,濃,鏡,漢,採,抗,遣,彡,崩,扱,菓,
    騒,属,_腕,築,賛,裁,固,狂,杉,削,紅,梅,縄,幕,候,底,瀬,束,欠,競,叫,益,裸,液,黄,紀,踏,討,鮮,厚,暮,督,
    貸,吐,耐,締,窓,_七,及,季,徹,閣,柄,雄,群,竹,盤,批,豪,損,臨,黙,棒,踊,敬,圏,句,庁,縁,龍,毒,尻,択,乾,
    履,革,織,浦,至,契,徳,塗,訴,炎,称,塩,某,肩,挨,拶,栄,魂,浴,床,操,趣,盗,衝,訪,童,焦,則,聖,垢,複,艸,
    籍,緑,秀,魅,審,穴,漏,副,奏,甲,砂,鍋,雲,宝,矢,宙,慎,献,貼,狙,汁,勧,双,殿,努,鈴,湾,_枝,諦,遺,奮,濯,
    包,凍,靴,鑑,嵐,謎,著,雰,埋,霊,幅,依,岸,昇,叩,拠,舎,徴,輝,剤,免,繰,熊,煙,償,巳,憩,均,煮,挑,陰,虫,
    胃,塚,埼,痴,皮,潟,悟,喋,飼,浅,従,須,灯,阿,釣,易,癖,距,筆,之,融,智,慮,縮,沼,粛,植,拝,輸,襲,熟,迫,
    豚,孫,仏,冊,績,奪,看,舗,尽,羨,揃,炉,炊,衆,珍,躍,尊,律,酸,郷,臣,逮,承,喉,潰,闇,褒,卵,晒,幌,懸,宗,
    鬱,厨,範,令,帳,粧,添,層,愚,獲,喫,偉,妖,麺,脚,帝,却,飽,諸,刑,滞,唯,譲,暑,駆,狩,署,貧,呑,陣,透,稲,
    亀,噂,幻,忍,彦,皇,嬢,氷,桃,揚,昭,溜,仁,彩,封,磨,析,殴,巡,執,棚,痩,偽,妊,竜,核,還,敷,航,如,獄,飾,
    哀,貯,控,滑,維,誠,皿,丼,針,拾,孤,沈,噌,僚,梨,較,糖,沙,拒,遇,臓,摘,塾,郡,堀,祖,貨,羅,枕,励,刷,璧,
    偏,沿,隆,兆,匂,_雷,噛,患,澤,柔,紫,唱,匹,鍵,惚,概,_雅,亜,棄,屈,寸,溶,只,缶,狭,浪,漁,賢,芝,潮,侵,浄,
    匠,駐,掘,玄,詐,曇,妬,抑,需,浩,綾,獣,湿,郵,畜,欺,雇,翔,抵,餅,債,曝,粋,鎖,緩,把,虚,銭,訓,遭,縛,威,
    冗,繧,戯,憧,招,随,麦,旬,旨,柳,岐,鶴,傾,勿,呪,舌,脂,賃,撤,撲,捜,戒,預,贈,寧,欧,騙,蓮,裂,覗,糸,偶,
    哲,項,摩,逢,浸,乃,排,没,謹,潤,糞,翼,菌,刀,云,泥,傘,稚,唐,罰,儀,憲,凸,爽,卑,噴,喰,祥,釈,喧,俗,雀,
    蹴,誇,揮,輔,膝,堪,眺,嫉,虎,炭,潜,斎,兼,貞,羊,慶,敏,繁,垣,苗,栃,涼,晶,騎,伴,抽,烈,尋,凹,遂,沸,摂,
    爪,燥,朗,猛,憂,栗,往,奨,帽,惨,翻,机,嶋,嘩,肝,畑,淡,馴,丘,漬,湖,繝,杏,粒,鶏,柏,菊,餃,斉,忠,濡,股,
    舐,冒,溢,卓,袖,叶,慰,紛,淫,揉,垂,翌,伏,牧,邦,剛,斬,吾,頻,召,詩,殊,硬,覇,芋,械,鳩,疎,俊,仰,佳,渉,
    述,縦,銃,虐,譜,尿,阻,倫,斗,貫,腸,尚,怠,蒼,弘,贅,咳,蒸,又,滝,煽,孝,拓,促,軒,柴,薦,暫,祉,丹,克,鎌,
    悶,霧,訂,戚,脇,偵,径,儲,蛇,銘,酬,釜,撫,拍,礎,搭,灰,阜,簿,敢,括,艦,疫,悠,砲,紳,挟,邸,旗,寛,宏,宴,
    掴,恩,憎,践,託,穏,貢,穂,婆,幽,剥,墓,椅,網,犠,倶,凶,弥,併,慌,昧,軟,盟,蘭,惜,唄,劣,酢,脅,拳,醤,欄,
    泳,牲,膨,征,娠,蓄,披,鍛,葛,謙,俳,顧,眉,伺,賠,誉,雛,飴,逸,抹,肥,瓶,兎,乏,肢,祐,絞,殆,椎,呆,淳,滋,
    宛,駒,隔,茂,鋼,陥,鷹,牡,敦,笠,堅,_盾,挿,肪,彰,愉,賊,厄,萎,亮,罠,恒,零,桐,詣,亭,唇,哉,刃,擬,岳,拭,
    嘆,醒,脈,寮,閲,巣,隙,潔,剰,殻,櫻,狼,葬,胞,勃,逝,猿,柱,喚,胡,シメ,猥,篠,粘,汰,班,禿,洒,彫,軸,凝,磁,
    謀,磯,鯖,腫,酎,弊,塔,姦,傍,序,泡,弄,磐,峰,_徐,稽,湧,愕,芽,瞳,猪,覆,綱,辻,炒,幾,弓,斐,扉,鈍,砕,堕,
    拘,凡,斜,錦,喪,琴,歪,罵,珈,宵,跳,腺,琲,筒,尖,迄,錯,畳,啓,捉,粗,符,絆,遥,湘,怯,漂,爺,叱,惹,冥,恨,
    箇,壮,旭,扇,架,頬,挫,繊,蘇,鼓,妥,掌,紗,虹,珠,騰,殖,矛,糧,搬,刈,圭,莉,暦,隅,菱,陶,荘,誓,桑,舘,蕎,
    綿,蛍,國,鉛,憤,萩,篇,馳,鎮,陛,澄,枯,僧,桁,伯,痒,蜜,遽,烏,塁,餌,妨,奉,幡,弦,餓,塊,鯛,曰,貝,蟹,泰,
    辱,凛,李,疾,胆,鋭,桂,戴,衰,隷,牙,媛,吊,佑,冠,鴨,洲,紋,笛,廊,膚,薇,痺,薔,淹,辿,塞,姐,喘,懲,葵,澪,
    函,蓋,蝶,賭,昆,苛,檎,玲,眩,梶,擦,芳,拙,霞,該,涯,苺,鉢,暁,昌,筑,芯,訟,柿,姜,慈,措,詮,筈,此,曖,滴,
    縫,棟,屍,詫,丿,藍,懇,椿,箸,苑,陳,溝,蔽,柚,蒲,盲,伎,崇,棋,撒,肺,狐,壇,惰,培,瓦,嘉,堺,遮,舫,俣,膜,
    朱,壱,赦,忌,曹,剃,旋,聡,諭,擁,痔,蜂,軌,傑,笹,癌,梓,這,獅,掻,緯,捧,屁,隈,濁,串,諏,籠,巧,淵,髭,栽,
    庄,朴,鞄,淋,穫,訊,槽,釘,姓,茅,冴,傲,錠,_錬,玩,巾,其,琉,紺,賑,洞,遡,遼,瑞,廻,耕,酵,堤,瑠,茎,煎,墨,
    壌,顎,稀,匿,漠,醸,呈,鉱,曽,苔,渇,溺,纏,躊,叔,躇,薙,梱,紐,薫,奢,朋,骸,伐,粥,蠣,綻,姪,甥,荻,栓,嗚,
    駿,碧,孔,塵,頓,艶,飢,晃,恭,乞,尺,煩,循,囁,憑,累,鳳,庵,樽,弐,鷲,蹄,据,凌,顕,巫,盆,媒,肯,搾,悦,迅,
    栖,箒,拉,槌,眞,緋,槍,郊,醜,篤,卸,亘,捻,辰,鮭,詠,碁,_侍,尼,杖,鮎,來,吟,狗,僅,橘,貿,舟,喝,捏,侮,甚,
    秩,礫,芦,帆,謡,茹,吠,縲,槻,韻,刹,晋,些,睨,閃,但,猟,媚,鐘,瞑,庶,矯,耶,銅,畿,讃,貌,蚊,嗅,痢,棲,卯,
    呉,蔑,壼,璃,鹸,愁,饅,耗,郁,遍,祷,窪,綴,遙,杜,慨,仔,薩,炸,裾,坪,溘,鯉,燐,娯,膳,鯨,翠,梁,附,袴,囚,
    窮,拗,胴,宰,准,嗜,欝,訣,蛮,拷,慕,赴,濱,靖,楼,臆,禅,胎,颯,爵,楚,髄,椒,陵,悼,窃,霜,卍,屑,羞,穀,挽,
    應,鱗,彷,茸,崖,肘,漆,涛,麿,柑,篭,鵜,寅,窒,賄,怨,閑,憫,鎧,从,或,曾,墜,洩,朔,嶺,廿,茄,唾,藻,貪,渦,
    秤,尉,湊,朽,憐,雫,讐,諾,廉,頁,脆,碗,峠,穿,廣,條,襟,肛,渕,慧,凪,郭,妃,且,兜,气,疹,謳,虜,酌,琶,痕,
    琵,淀,瞼,隼,迂,絢,屮,拐,汐,楠,瀧,唆,劉,鞭,汲,焉,惣,滾,捐,劫,琥,冨,晦,棺,蝉,窟,勲,紘,紬,膏,捗,洪,
    徊,徘,攣,肴,婿,廷,嘔,莫,焚,芥,桶,樋,於,幣,秦,楓,冤,逐,箋,瑛,侑,埃,撰,祓,葱,享,譚,巴,猶,賽,氣,吃,
    嬲,姑,峨,燕,瓜,畠,灘,壺,橙,牌,咥,升,醍,鼠,謂,凜,毅,聯,摯,醐,孕,萬,叙,儚,灸,后,泌,遷,煌,遜,屓,叉,
    茉,貶,峡,贔,臼,睦,鍼,榊,雌,渚,漕,邉,俄,頷,坐,嘲,轢,縞,闊,蒙,隕,惧,涌,嗣,隻,玖,倖,彙,蛛,蛙,樺,陀,
    絹,鞘,蒟,帖,蒻,慄,蜘,釧,藝,蔓,渓,翫,沌,艇,俵,唖,腑,蔭,枢,賜,竿,壷,峯,腿,扶,衡,鉾,孵,瘍,轄,瀕,嵌,
    奔,腎,閥,藩,繕,魁,梗,播,豹,妓,轟,蟲,蒔,汎,燗,侶,滲,狸,紡,蓬,渾,昏,蟻,錆,旺,斑,喩,樫,苫,裟,繍,淑,
    牽,鰻,齋,鷺,昴,迦,葎,訛,肖,儘,銚,祇,餡,蠍,填,彿,浣,夷,麟,茜,痙,鮫,訃,栞,糾,巷,斧,碑,朧,凱,珀,仇,
    禄,榎,粕,躾,踪,咎,穢,柊,癶,輿,汝,抄,逗,怜,爛,菩,儂,罹,膣,唸,灼,帥,燈,柘,剖,咽,牢,姻,嬌,亞,膿,岬,
    墟,袈,坦,鶯,伽,悸,槙,贄,腱,捌,學,俯,螺,焔,鰹,炙,硝,凰,禍,靭,珂,憾,采,麹,丑,騨,汽,乂,黎,宍,吶,鰤,
    瞭,漱,硫,鴉,雁,窯,稔,芹,脊,涎,莱,卿,酪,鵬,泄,頸,麒,錫,楢,團,會,塀,畏,巌,蝋,琢,祟,倣,肋,蝕,藁,几,
    腔,叢,檻,邊,皐,箕,傭,駕,薪,褌,已,屯,鍾,檜,懺,濤,筐,昂,楊,蕾,閻,砥,膀,掟,櫂,胱,檀,堵,奄,漸,睫,窶,
    迭,榴,柵,扁,滸,鞍,徨,逞,殲,鱈,厭,蝿,梯,繚,祀,謗,綜,哺,侯,冫,个,馨,恰,琳,燻,佃,箔,疼,梵,捲,跨,沁,
    賓,杭,椛,檄,鴻,脛,麓,頒,淘,董,魏,邑,砦,恣,誹,耽,峙,俸,趙,佇,倦,勾,粟,筍,暢,牟,恫,萃,伍,揶,鰐,顏,
    很,嚇,揄,燵,彗,濫,摺,炬,蜷,羹,乖,寡,薮,匚,庇,屏,冲,狛,侠,褻,麩,叡,褐,穹,瑚,翁,囃,靡,冑,葡,甦,庸,
    毀,蕁,冶,磔,揆,躁,喬,憬,芭,卦,諜,孟,弔,焙,墳,瞰,殉,諫,辟,爬,蜀,樂,餐,辣,牝,酉,煉,蟄,朦,而,竈,萄,
    蛾,撼,藪,桔,軋,吻,鮨,荳,菖,緻,燭,噺,舶,穣,欽,舵,裳,惇,榛,仝,鞠,曙,僻,餉,腋,丞,惟,敲,厩,咄,嗟,哭,
    譁,廟,皺,棘,逹,霖,翡,蛸,臥,嘗,戮,凧,漣,絨,枷,瞞,鋳,爾,哈,涜,憚,疇,洛,撥,發,斤,與,蹊,糊,壹,裔,什,
    蕩,套,褪,蝦,灣,櫛,弛,珊,驕,毯,沫,嶽,擢,稜,轍,咬,碇,蕉,繭,娼,妾,弧,鸞,涅,詭,杵,侘,癪,礁,款,坑,遵,
    鼎,濾,毘,屠,槭,攫,魄,鵠,鰯,躙,螟,箪,槇,蜃,壬,宋,莠,帙,狡,賂,斯,輌,邁,匡,釉,曳,魎,咀,啼,丶,逼,圓,
    攘,椀,畔,痣,鮪,倥,亨,痰,壽,蹂,齧,抉,蕨,饒,暈,棗,衿,杞,烹,氾,戎,嚼,甜,槃,鵺,娩,燦,閖,勅,躓,恍,賦,
    捺,岱,晰,瑜,實,簾,戌,蹟,霙,亥,罫,踵,誅,傀,咆,鯵,蠅,疱,榮,鋏,堆,魍,ガ,ギ,グ,ゲ,ゴ,ザ,ジ,ズ,ゼ,ゾ,
    ダ,ヂ,ヅ,デ,ド,バ,ビ,ブ,ベ,ボ,パ,ピ,プ,ペ,ポ,
    sizurusFonts_end = -99999999,
};

class SKFont{
    SKFont();
    SKFont(const SKFont&);
    ~SKFont();
public:
    static void drawString_toWindow(const SizurusFontsName drawFont, const GMRect2D& destRect, GMSpriteBatch* s, GMColor c = GMColor::White);
    // 文字列から、静流フォント配列にコンバートして返す。配列には、予め256バイトくらい用意しとこうよ。
    // 日本語以外はバグるんるん 第二引数は、濁点つけるかどうか。
    static void convertChar2Name(SizurusFontsName* fontNames, ten_flags* flags, const std::string& str);
 
    // 一文字のみを描画する。
    // 自由回転、自由拡縮、カラー指定描画が可能。時空亜空の言葉のために、追加したメソッド。
    static void drawCharacter(const char* character, GMSpriteBatch* s, const GMRect2D& destRect, const GMColor& color, double rotation, const GMVector2D& origin);
};

}