def copy_to_end(original_str, copy_location, original_length, max_length):
    i = original_length - 1
    j = max_length - 1
    while i >= 0:
        copy_location[j] = original_str[i]
        i -= 1
        j -= 1

tests = int(raw_input())
while tests > 0:
    tests -= 1
    first_inp = raw_input()
    second_inp = raw_input()

    if second_inp == "0":
        print(0)
        continue

    first_len = len(first_inp)
    second_len = len(second_inp)
    max_length = max(first_len, second_len)

    first_num = ['0'] * max_length
    second_num = ['0'] * max_length

    copy_to_end(first_inp, first_num, first_len, max_length)
    copy_to_end(second_inp, second_num, second_len, max_length)

    is_active = False
    cur_len = 0
    i = max_length - 1
    ans = 0

    while i >= 0:
        if is_active:
            if first_num[i] != second_num[i]:
                # XOR is active so continue
                cur_len += 1
            elif first_num[i] == second_num[i]:
                if cur_len > ans:
                    ans = cur_len
                if first_num[i] == '1':
                    cur_len = 1
                    is_active = True
                else:
                    cur_len = 0
                    is_active = False
        elif first_num[i] == second_num[i] and first_num[i] == '1':
            is_active = True
            cur_len = 1
        i -= 1

    if is_active:
        if cur_len > ans:
            ans = cur_len

    print(ans + 1)