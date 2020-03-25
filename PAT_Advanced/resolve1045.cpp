#include "resolve1045.h"
/*
	�����صĸ�����̰��
	����������Ϊ���þ�����С�Ĵ��ۣ�ɾȥĳ����ɫ����ÿ����ɫ����ֵΪ0������˳��
	��stripe�е�ÿ����ɫ��������ֵ
	ÿ��ɾȥ��ֵ�����Ϊ����/���򣩵���ɫ�����¼�����ֱֵ��ÿ����ɫ����ֵ��Ϊ0
	���ֻ����һ�����Ե� ��˼·����ܴ�==��
	int resolve1045::resolve()
	{
	int num_of_colors = 0, length_of_order = 0, length_of_stripe = 0;
	scanf("%d\n%d", &num_of_colors, &length_of_order);
	//��¼ÿ����ɫ�ĺ�����Գ�����Щ��ɫ
	bool** order_map = new bool*[num_of_colors + 1];
	for (size_t i = 0; i < num_of_colors + 1; ++i)
	{
	//�˴�����boolĬ��Ϊtrue�����ԣ�ȡ��
	order_map[i] = new bool[num_of_colors + 1];
	}
	int int_temp = 0;
	vector<int> vec_order;
	for (size_t i = 0; i < length_of_order; ++i)
	{
	scanf("%d", &int_temp);
	vec_order.push_back(int_temp);
	for (size_t j = 0; j < vec_order.size(); ++j)
	{
	order_map[vec_order[j]][int_temp] = false;
	}
	}
	vector<int> stripe;
	scanf("%d", &length_of_stripe);
	stripe.reserve(length_of_stripe);
	for (size_t i = 0; i < length_of_stripe; ++i)
	{
	scanf("%d", &int_temp);
	if (!order_map[int_temp][int_temp])
	{
	//�ȰѲ����������ֵ���˵�
	//stripe_node* node = new stripe_node();
	//node->color = int_temp;
	//node->entropy = 0;
	//stripe.push_back(node);
	stripe.push_back(int_temp);
	}
	}
	stripe_node_iterator max_entropy_it = find_max_entropy(stripe, order_map);
	while (max_entropy_it != stripe.end())
	{
	stripe.erase(max_entropy_it);
	max_entropy_it = find_max_entropy(stripe, order_map);
	}
	cout << stripe.size();
	return 0;
	}

	resolve1045::stripe_node_iterator resolve1045::find_max_entropy(vector<int>& stripe, bool ** order_map)
	{
	stripe_node_iterator result = stripe.end();
	int color = 0;
	int max_entropy = 0;
	int current_entropy = 0;
	for (stripe_node_iterator it = stripe.begin(); it != stripe.end(); ++it)
	{
	color = (*(it));
	current_entropy = 0;
	for (stripe_node_iterator it_temp = it + 1; it_temp != stripe.end() && order_map[color][(*(it_temp))]; ++it_temp)
	{
	//��������˳�������Ҫɾȥ���ٸ���ɫ�����������˳�򣬼���ֵ
	++current_entropy;
	}
	if (current_entropy > max_entropy)
	{
	result = it;
	max_entropy = current_entropy;
	}
	}
	return result;
	}

	����ɾȥ��ǰ��ֵ������ɫ������һ���ܵõ�ȫ�����ŵĽ�
	ȥ�˽�����󲻽�������
	
	�𰸵�˼·����֮ǰ�����·���е��� ���·���ǿ�����������·��
	���Ǵ����ϵ�ÿһ����ɫi ��iǰ���ÿһ����ɫj���һ������
	����ɫ˳�� j i ����order����j���Եִ�i��
	��ô�õ�һ������Ϊlength[j]+1�İ�����j����ɫ�͵�i����ɫ��stripe���õ�һ������Ϊlength[j]+1�Ĵ�1����j��i��·����
	�����еİ�����i����ɫ��stripe�������length[i]�Ƚϣ��ж��Ƿ�Ϊ������һ������ ��������·�����ȱȽϣ��ж��Ƿ�Ϊ�µĵȳ�·�������·����
	�Դ�����ÿһ����ɫ���Ӷ������Ĵ��ӵĳ����Ƕ���
	
	�𰸱���û�����������������ɫ����Ӧ�ÿ��Բ������·������ȥ��¼·���ڵ�
	
	��˵������ô��⵽order�����ɫ�����ظ���==

	
*/
int resolve1045::resolve()
{
	int num_of_colors = 0, length_of_order = 0, length_of_stripe = 0;
	scanf("%d\n%d", &num_of_colors, &length_of_order);
	//��¼ÿ����ɫ��λ��
	int* color_order = new int[num_of_colors + 1];
	fill(color_order, color_order + num_of_colors+1,0);
	int int_temp = 0;
	vector<int> vec_order;
	for (size_t i = 1; i <= length_of_order; ++i)
	{
		scanf("%d", &int_temp);
		color_order[int_temp]=i;
	}
	vector<stripe_node*> stripe;
	scanf("%d", &length_of_stripe);
	stripe.reserve(length_of_stripe);
	for (size_t i = 0; i < length_of_stripe; ++i)
	{
		scanf("%d", &int_temp);
		if (color_order[int_temp])
		{
			//�ȰѲ����������ֵ���˵�
			stripe_node* node = node = new stripe_node();
			node->color = int_temp;
			node->length = 0;
			stripe.push_back(node);
		}
	}
	int max_length = 0;
	for (size_t i = 0; i < stripe.size(); ++i)
	{
		stripe[i]->length = 1;
		for (size_t j = 0; j < i; j++)
		{
			if (color_order[stripe[j]->color]<=color_order[stripe[i]->color])
			{
				//����˳�򣬿������һ������
				stripe[i]->length = max(stripe[i]->length, stripe[j]->length + 1);
			}
		}
		max_length=max(max_length, stripe[i]->length);
	}
	cout << max_length;
	return 0;
}