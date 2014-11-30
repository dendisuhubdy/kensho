# Given a time-series of length 260 generated by:
#
# p(t) = 100 + sum[sin(t * c_i)] for c_i in
# c = [46, 64, 98, 99, 101, 104, 106, 107, 109, 110, 111, 111, 111, 115, 115]
#
# Calculate the returns based on the following strategy:
# Hold the stock when it is within the closed interval [98, 101] and
# sell at the end of the time series if still holding.
#
# So, if the time series was:
# [96, 97, 98, 102, 100, 100, 100, 96]
#
# The strategy would (N=do nothing, B=buy, S=sell):
# [N, N, B, S, B, N, N, S]
#
# What is the cumulative percentage return using this strategy:
# 1) simply on a percentage return basis
# e.g., day 1: 10%, day 2: 10%, total return would be 21% after two days.
#
# 2) assuming $1000.00 of starting capital and only purchasing whole “shares”
#
# Please spend less than an hour on this. Partial solutions are acceptable.
# Consider this a conversation starter.
#
# Great quality code is preferred over short correct answers.
# Write code in a style you feel comfortable discussing.
#
# Python preferred, but we’ll take any language we can bootstrap an
# environment for.